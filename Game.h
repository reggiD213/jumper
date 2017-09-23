#pragma once

#include <memory>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "SpriteRenderer.h"
#include "Entity.h"



class Game
{
private:
	enum class GameState {
		MENU, ACTIVE, QUIT
	};
public:
	Game(int width, int height);
	~Game();
		
	void fps(double getTime);
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

	GLuint VAO;

	std::unique_ptr<SpriteRenderer> renderer;

	std::unique_ptr<Entity> player;
	std::vector<std::shared_ptr<Entity>> entities;
};

