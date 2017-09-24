#include "Player.h"

#include <iostream>

Player::Player(Texture2D& texture, glm::vec2 pos, glm::vec2 size, glm::vec3 color, GLfloat rot, glm::vec2 vel)
	: Entity(texture, pos, size, color, rot, vel)
{
	acc.y = gravitationalConstant;
	boundingBox.size = { size.x - 20, size.y };
}

void Player::update(float dt)
{
	// left/right movement
	// reset x-vel on x-collision
	if (collisionSides.left && vel.x > 0)
		vel.x = 0;
	else if (collisionSides.right && vel.x < 0)
		vel.x = 0;

	// check if already moving or trying to move
	if (vel.x < -10 || vel.x > 10 || forceDir.x != 0)
		vel.x += (forceDir.x * force - sgn(vel.x) * friction) * dt;
	else
		vel.x = 0;
	
	// Running modifier
	movementSpeed = isRunning ? 600.0f : 300.0f;
		
	// boundaries
	if (vel.x <= -movementSpeed)
		vel.x = -movementSpeed;
	if (vel.x >= movementSpeed)
		vel.x = movementSpeed;
	
	// move horizontal
	pos.x += vel.x * dt;
	
	// reset y-vel on y-collision
	if (collisionSides.top)
		vel.y = 0;
	else if (collisionSides.bottom)
		if (vel.y > 0)
			vel.y = 0.0f;
	
	// try to jump
	if (tryJump == true && collisionSides.top)
		vel.y = initialVelocity;
	
	//move vertical
	pos.y -= vel.y * dt + 1 / 2 * acc.y * dt * dt;
	
	//calculate and reset things for next cycle
	vel.y += acc.y * dt;
	boundingBox.pos = { pos.x + 10, pos.y };
	
	//std::cout << collisionSides.top << collisionSides.bottom << collisionSides.left << collisionSides.right << std::endl;

	collisionSides = { false, false, false, false };
	tryJump = false;
}

void Player::jump()
{
	tryJump = true;
}

void Player::reset(glm::vec2 pos, glm::vec2 size)
{
	this->pos = pos;
	this->size = size;
	vel = { 0,0 };
}

void Player::collidedWith(const GameObject& object, Rect::Side side)
{
	switch (side)
	{
	case Rect::Side::Top:
		collisionSides.top = true;
		boundingBox.pos.y = object.getPos().y - size.y;
		break;
	case Rect::Side::Bottom:
		collisionSides.bottom = true;
		boundingBox.pos.y = object.getPos().y + object.getSize().y;
		break;
	case Rect::Side::Left:
		collisionSides.left = true;
		boundingBox.pos.x = object.getPos().x - boundingBox.size.x;
		break;
	case Rect::Side::Right:
		collisionSides.right = true;
		boundingBox.pos.x = object.getPos().x + object.getSize().x;
		break;
	case Rect::Side::None:
	default:
		break;
	}
	
}

void Player::run(bool on)
{
	isRunning = on;
}

void Player::setForceDirection(Direction dir)
{
	forceDir.x = (float)dir;
}
