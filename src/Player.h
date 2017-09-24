#pragma once

#include "Entity.h"

#include <glm/glm.hpp>
#include <vector>

class Player : public Entity
{
private:
	// todo: move to helpers
	template <typename T> int sgn(T val) {
		return (T(0) < val) - (val < T(0));
	}

	struct {
		bool left = false;
		bool right = false;
		bool top = false;
		bool bottom = false;
	} collisionSides;

	// needs rework (horiz movement
	float friction = 1000.0f;
	float force = 1500.f;
	float maxSpeed = 300.0f;

	bool isRunning = false;
	bool tryJump = false;
	
	glm::vec2 forceDir{ 0,0 };
	glm::vec2 movingDir{ 0,0 };

	std::vector<GameObject>colliding;

	static constexpr float jumpHeight = 200.0f;
	static constexpr float jumpDistance = 200.0f;
	static constexpr float maxMovementSpeed = 600.0f;
	static constexpr float gravitationalConstant = -2 * jumpHeight * (maxMovementSpeed * maxMovementSpeed) / (jumpDistance * jumpDistance);
	static constexpr float initialVelocity = 2 * jumpHeight * maxMovementSpeed / jumpDistance;
	
	float movementSpeed = 300.0f;

public:
	Player(Texture2D& texture, glm::vec2 pos, glm::vec2 size, glm::vec3 color = { 1, 1, 1 }, GLfloat rot = 0.0f, glm::vec2 vel = { 0, 0 });

	void update(float dt);

	void jump();
	void reset(glm::vec2 pos, glm::vec2 size);
	void collidedWith(const GameObject& object, Rect::Side side);

	void run(bool on = true);
	void setForceDirection(Direction dir);

};

