#include "Game.h"

#include <iostream>
#include <string>
#include <sstream>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>


#include "ResourceManager.h"
#include "Input.h"

#include "Player.h"
#include "Block.h"
#include "Level.h"

Game::Game(int width, int height)
	: width(width),
	  height(height),
	  dt(0.0f),
	  last(0.0f),
	  state(GameState::MENU)
{
	// Shaders
	Shader& spriteShader = ResourceManager::createShader("sprite", "resources/shaders/sprite.vert", "resources/shaders/sprite.frag");
	glm::mat4 projection = glm::ortho(0.0f, (GLfloat)width, (GLfloat)height, 0.0f, -1.0f, 1.0f);
	spriteShader.use().uniformInt("image", 0);
	spriteShader.uniformMat4("projection", projection);

	// Textures
	ResourceManager::createTexture("background", "resources/textures/background.jpg");
	ResourceManager::createTexture("player", "resources/textures/entities/p1_front.png", true);
	ResourceManager::createTexture("grassLeft", "resources/textures/blocks/grassLeft.png", true);
	ResourceManager::createTexture("grassMiddle", "resources/textures/blocks/grassMid.png", true);
	ResourceManager::createTexture("grassRight", "resources/textures/blocks/grassRight.png", true);
	ResourceManager::createTexture("grass", "resources/textures/blocks/grass.png", true);
	ResourceManager::createTexture("brick", "resources/textures/blocks/brickWall.png", true);
	// Renderers
	renderer = std::make_unique<SpriteRenderer>(spriteShader);
	rectRenderer = std::make_unique<RectRenderer>(width, height);

	textRenderer = std::make_unique<TextRenderer>(width, height);
	textRenderer->Load("resources/fonts/ocraext.TTF", 24);

	// Game Objects
	player = std::make_unique<Player>(Player(ResourceManager::getTexture("player"), { 0, 0 }, { 40, 40 }));

	// Create Level and Objects from level
	ResourceManager::createLevel("test", "resources/levels/test.txt");
	ResourceManager::getLevel("test").createGameObjects();
	
	for (auto& block : ResourceManager::getLevel("test").blocks)
	{
		gameObjects.push_back(*block);
	}
}

Game::~Game()
{
}

void Game::fps(float getTime)
{
	dt = getTime - last;
	last = getTime;
}

void Game::input()
{
	// player input
	// running
	player->run(Input::keys[GLFW_KEY_LEFT_SHIFT]);

	if (Input::keys[GLFW_KEY_A] && Input::keys[GLFW_KEY_D] || !Input::keys[GLFW_KEY_A] && !Input::keys[GLFW_KEY_D])
		player->setForceDirection(Player::Direction::STOP);
	else if (Input::keys[GLFW_KEY_A])
		player->setForceDirection(Player::Direction::LEFT);
	else if (Input::keys[GLFW_KEY_D])
		player->setForceDirection(Player::Direction::RIGHT);
	if (Input::keys[GLFW_KEY_SPACE])
		player->jump();
	if (Input::keys[GLFW_KEY_R])
		player->reset({ 0, 0 }, { 40, 40 });
	if (Input::keys[GLFW_KEY_F1] && !Input::keysProcessed[GLFW_KEY_F1])
	{
		dbg.debugFps = !dbg.debugFps;
		Input::keysProcessed[GLFW_KEY_F1] = true;
	}
	if (Input::keys[GLFW_KEY_F2] && !Input::keysProcessed[GLFW_KEY_F2])
	{
		dbg.debugPlayer = !dbg.debugPlayer;
		Input::keysProcessed[GLFW_KEY_F2] = true;
	}
	if (Input::keys[GLFW_KEY_F3] && !Input::keysProcessed[GLFW_KEY_F3])
	{
		dbg.debugBounding = !dbg.debugBounding;
		Input::keysProcessed[GLFW_KEY_F3] = true;
	}
}

void Game::update()
{
	//Player collision
	for (const auto& gameObject : gameObjects)
	{
		player->collidedWith(gameObject, player->collision(gameObject));
	}

	player->update(dt);

	dbg.update(dt, *player, gameObjects);
}

void Game::render()
{
	glClearColor(0.0f, 0.4f, 0.4f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	ResourceManager::getShader("sprite").use();

	renderer->drawSprite(ResourceManager::getTexture("background"), glm::vec2(0, 0), glm::vec2(width, height));

	//for (int i = 0; i < 100; i++) // performance? draw every entity a 100 times!
	ResourceManager::getLevel("test").draw(*renderer);
	
	
	player->draw(*renderer);

	dbg.draw(*rectRenderer, *textRenderer, width, height);
}
