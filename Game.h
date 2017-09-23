#pragma once

#include <memory>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "SpriteRenderer.h"
#include "Entity.h"

enum class GameState {
	MENU, ACTIVE, QUIT
};


class Game
{
public:
	// Constructor/Destructor (evtl. unnecessary since we can initialize variables in c++11 directly)
	Game();
	~Game();

	
	void init(int width, int height);
	void fps(double getTime);
	void input();
	void update();
	void render();

private:
	// Delta Time
	float dt = 0.0f, last = 0.0f;
	// Viewport Dimensions
	int width = 0, height = 0;
	// Current Game State
	GameState state = GameState::MENU;

	GLuint VAO;

	std::unique_ptr<SpriteRenderer> renderer;

	std::unique_ptr<Entity> player;
	std::vector<std::shared_ptr<Entity>> entities;
	//std::map<std::string, std::unique_ptr<Entity>> entities;
};

