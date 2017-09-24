#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Texture2D.h"
#include "SpriteRenderer.h"
#include "Rect.h"

class GameObject
{
public:
	GameObject(Texture2D& texture, glm::vec2 pos, glm::vec2 size, glm::vec3 color = glm::vec3(1), GLfloat rot = 0.0f);

	void draw(SpriteRenderer& renderer);

	const glm::vec2& getPos() const { return pos; }
	const glm::vec2& getSize() const { return size; }
	Rect boundingBox;

	

protected:
	Texture2D& texture;
	glm::vec2 pos;
	glm::vec2 size;
	glm::vec3 color;
	GLfloat rot;
};

