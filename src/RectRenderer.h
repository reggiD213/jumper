#pragma once

#include <glm/glm.hpp>

#include "Shader.h"
#include "Rect.h"


class RectRenderer
{
public:
	RectRenderer(GLuint width, GLuint height);
	void drawRect(Rect& rect, glm::vec4 color = glm::vec4(1.0f));

private:
	Shader shader;
	void init();
	// Render state
	GLuint VAO;
};
