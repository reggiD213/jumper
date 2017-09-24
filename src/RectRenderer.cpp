#include "RectRenderer.h"

#include <glm/gtc/matrix_transform.hpp>
#include <iostream>

#include "ResourceManager.h"

RectRenderer::RectRenderer(GLuint width, GLuint height)
{
	// Load and configure shader
	shader = ResourceManager::createShader("rect", "resources/shaders/boundingBox.vert", "resources/shaders/boundingBox.frag");
	shader.use().uniformMat4("projection", glm::ortho(0.0f, (float)width, (float)height, 0.0f));

	init();
}

void RectRenderer::drawRect(Rect& rect, glm::vec4 color)
{
	shader.use();

	// transformations
	glm::mat4 model;
	// translate
	model = glm::translate(model, glm::vec3(rect.pos, 0.0f));

	// scale
	model = glm::scale(model, glm::vec3(rect.size, 1.0f));
	shader.uniformMat4("model", model);

	shader.uniformVec4("spriteColor", color);

	// render textured quad
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}

void RectRenderer::init()
{
	
	GLuint VBO, EBO;
	GLfloat vertices[] = {
		// Pos
		0.0f, 1.0f, // Top Left
		0.0f, 0.0f, // Bottom Left
		1.0f, 1.0f, // Top Right
		1.0f, 0.0f, // Bottom Right
	};

	GLuint indices[] = {
		0, 1, 2,
		2, 1, 3
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0 * sizeof(GLfloat), (GLvoid*)0);

	glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}