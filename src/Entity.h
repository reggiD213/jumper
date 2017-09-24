#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>

#include "GameObject.h"
#include "Rect.h"

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
	Entity(Texture2D& texture, glm::vec2 pos, glm::vec2 size, glm::vec3 color = glm::vec3(1), GLfloat rot = 0.0f, glm::vec2 vel = glm::vec2(0));

	friend std::ostream& operator<<(std::ostream& out, const Entity& e);

	Rect::Side collision(const GameObject& object);

protected:
	glm::vec2 vel;
	glm::vec2 acc;

	bool standing;

};

