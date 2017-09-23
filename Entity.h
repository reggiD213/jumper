#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "GameObject.h"

#include "Texture2D.h"

class Entity : public GameObject
{
public:
	enum class Direction
	{
		LEFT = -1,
		RIGHT = 1,
		STOP = 0
	};

public:
	Entity(Texture2D& texture, glm::vec2 pos, glm::vec2 size, glm::vec3 color = { 1, 1, 1 }, GLfloat rot = 0.0f, glm::vec2 vel = { 0, 0 });

	virtual void update(float dt) = 0;

	virtual void setForceDirection(Direction dir) = 0;
	virtual void run(bool on = true) = 0;

protected:
	glm::vec2 vel;

};

