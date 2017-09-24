#pragma once

#include <glm/glm.hpp>

class Rect
{
public:
	Rect();
	~Rect();
	
	enum class Side
	{
		None,
		Top,
		Bottom,
		Left,
		Right
	};

	glm::vec2 pos;
	glm::vec2 size;

	Side collision(const Rect& other);
};

