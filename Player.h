#pragma once

#include "Entity.h"

#include <glm/glm.hpp>

class Player : public Entity
{
private:
	float friction = 1000.0f;
	float force = 1500.f;
	float maxSpeed = 300.0f;

	bool isRunning = false;
	
	glm::vec2 forceDir{ 0,0 };
	glm::vec2 movingDir{ 0,0 };


public:
	Player(glm::vec2 pos, glm::vec2 size, glm::vec2 vel, glm::vec3 color, GLfloat rot, Texture2D& texture);

	virtual void update(float dt);

	virtual void run(bool on = true);
	virtual void setForceDirection(Direction dir);
};

