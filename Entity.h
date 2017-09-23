#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "SpriteRenderer.h"
#include "Texture2D.h"

enum class Direction
{
	LEFT = -1,
	RIGHT = 1,
	STOP = 0
};

class Entity
{
public:
	glm::vec2 pos;
	glm::vec2 size;
	glm::vec2 vel;
	glm::vec3 color;
	GLfloat rot;
	Texture2D& texture;

	Entity(glm::vec2 pos, glm::vec2 size, glm::vec2 vel, glm::vec3 color, GLfloat rot, Texture2D& texture);

	void draw(SpriteRenderer& renderer);

	virtual void update(float dt) = 0;

	virtual void setForceDirection(Direction dir) = 0;
	virtual void run(bool on = true) = 0;
private:

};

