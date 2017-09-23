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
	Shader& spriteShader = ResourceManager::createShader("sprite", "shaders/sprite.vert", "shaders/sprite.frag");
	glm::mat4 projection = glm::ortho(0.0f, (GLfloat)width, (GLfloat)height, 0.0f, -1.0f, 1.0f);
	spriteShader.use().uniformInt("image", 0);
	spriteShader.uniformMat4("projection", projection);

	// Textures
	ResourceManager::createTexture("background", "textures/background.jpg");
	ResourceManager::createTexture("player", "textures/entities/p1_front.png", true);
	ResourceManager::createTexture("grassLeft", "textures/blocks/grassLeft.png", true);
	ResourceManager::createTexture("grassMiddle", "textures/blocks/grassMid.png", true);
	ResourceManager::createTexture("grassRight", "textures/blocks/grassRight.png", true);
	ResourceManager::createTexture("grass", "textures/blocks/grass.png", true);
	ResourceManager::createTexture("brick", "textures/blocks/brickWall.png", true);
	// Renderers
	renderer = std::make_unique<SpriteRenderer>(spriteShader);

	// Game Objects
	player = std::make_unique<Player>(Player(ResourceManager::getTexture("player"), { 0, height - 80 }, { 40, 40 }, { 1, 1, 1 }, 0.0f, { 0, 0 }));

	// Create Level and Objects from level
	ResourceManager::createLevel("test", "resources/test.txt");
	ResourceManager::getLevel("test").createEntities();
	for (auto block : ResourceManager::getLevel("test").blocks)
	{
		gameObjects.push_back(block);
	}
}

Game::~Game()
{
}

void Game::fps(double getTime)
{
	dt = (float)getTime - last;
	last = (float)getTime;
	double fps = 1 / dt;
	//std::cout << fps << std::endl; //debug fps?
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
}

void Game::update()
{
	player->update(dt);
	ResourceManager::getLevel("test").update();
}

void Game::render()
{
	glClearColor(0.0f, 0.0f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	ResourceManager::getShader("sprite").use();

	renderer->drawSprite(ResourceManager::getTexture("background"), glm::vec2(0, 0), glm::vec2(width, height));

	//for (int i = 0; i < 100; i++) // performance? draw every entity a 100 times!
	ResourceManager::getLevel("test").draw(*renderer);
	
	player->draw(*renderer);
	
}
