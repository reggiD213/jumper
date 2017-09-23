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

	static constexpr float jumpHeight = 200.0f;
	static constexpr float jumpDistance = 200.0f;
	static constexpr float movementSpeed = 300.0f;

	static constexpr float initialVelocity = 2 * jumpHeight * movementSpeed / jumpDistance;
	static constexpr float gravitationalConstant = -2 * jumpHeight * (movementSpeed * movementSpeed) / (jumpDistance * jumpDistance);


public:
	Player(Texture2D& texture, glm::vec2 pos, glm::vec2 size, glm::vec3 color = { 1, 1, 1 }, GLfloat rot = 0.0f, glm::vec2 vel = { 0, 0 });

	virtual void update(float dt);

	void jump(float dt);
	void reset(glm::vec2 pos, glm::vec2 size);
	


	virtual void run(bool on = true);
	virtual void setForceDirection(Direction dir);
};

