#pragma once

#include <memory>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "SpriteRenderer.h"
#include "RectRenderer.h"
#include "TextRenderer.h"
#include "Entity.h"
#include "Player.h"
#include "Debugger.h"



class Game
{
private:
	enum class GameState {
		MENU, ACTIVE, QUIT
	};
public:
	Game(int width, int height);
	~Game();
	
	void fps(float getTime);
	void input();
	void update();
	void render();

private:
	// Delta Time
	float dt, last;
	// Viewport Dimensions
	const int width, height;
	// Current Game State
	GameState state;
	Debugger dbg;

	GLuint VAO;

	std::unique_ptr<SpriteRenderer> renderer;
	std::unique_ptr<RectRenderer> rectRenderer;
	std::unique_ptr<TextRenderer> textRenderer;

	std::unique_ptr<Player> player;
	std::vector<GameObject> gameObjects;
};

