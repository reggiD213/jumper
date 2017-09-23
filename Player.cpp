#include "Player.h"

#include <iostream>

Player::Player(glm::vec2 pos, glm::vec2 size, glm::vec2 vel, glm::vec3 color, GLfloat rot, Texture2D& texture)
	: Entity(pos, size, vel, color, rot, texture)
{

}

void Player::update(float dt)
{
	//force = 1500;
	//friction = 1000;
	// Running modifier
	maxSpeed = isRunning ? 600.0f : 300.0f;
	
	// Check if moving or player tries to move
	if (vel.x < -10 || vel.x > 10 || forceDir.x != 0)
	{
		// Check moving direction
		if (vel.x < -10)
			movingDir.x = -1;
		else if (vel.x > 10)
			movingDir.x = 1;

		vel.x += (forceDir.x * force - movingDir.x * friction) * dt;
	}
	else
	{
		movingDir.x = 0;
		vel.x = 0;
	}
	
	
	// boundaries
	if (vel.x <= -maxSpeed)
		vel.x = -maxSpeed;
	if (vel.x >= maxSpeed)
		vel.x = maxSpeed;

	//std::cout << vel.x << "\t" << forceDir.x << "\t" << movingDir.x << "\t" << force << "\t" << friction << std::endl;
	
	// move player
	pos.x += vel.x * dt;
}

void Player::run(bool on)
{
	isRunning = on;
}

void Player::setForceDirection(Direction dir)
{
	forceDir.x = static_cast<float>(dir);
}
