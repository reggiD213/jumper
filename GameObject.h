#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Texture2D.h"
#include "SpriteRenderer.h"

class GameObject
{
public:
	GameObject(Texture2D& texture, glm::vec2 pos, glm::vec2 size, glm::vec3 color = { 1, 1, 1 }, GLfloat rot = 0.0f);

	void draw(SpriteRenderer& renderer);

protected:
	glm::vec2 pos;
	glm::vec2 size;
	glm::vec3 color;
	GLfloat rot;
	Texture2D& texture;
};

