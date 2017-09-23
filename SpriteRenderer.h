#pragma once

#include <glm/glm.hpp>

#include "Shader.h"
#include "Texture2D.h"

class SpriteRenderer
{
public:
	SpriteRenderer(Shader& shader);
	~SpriteRenderer();

	void drawSprite(Texture2D& texture, glm::vec2 pos, glm::vec2 size = glm::vec2(100, 100), GLfloat rotate = 0.0f, glm::vec3 color = glm::vec3(1.0f));
private:
	Shader shader;
	GLuint VAO;
	void init();
};

