#include "SpriteRenderer.h"

#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

SpriteRenderer::SpriteRenderer(Shader& shader)
{
	this->shader = shader;
	init();
}


SpriteRenderer::~SpriteRenderer()
{
	glDeleteVertexArrays(1, &VAO);
}

void SpriteRenderer::drawSprite(Texture2D& texture, glm::vec2 pos, glm::vec2 size, GLfloat rotate, glm::vec3 color)
{
	shader.use();

	// transformations
	glm::mat4 model;
	// translate
	model = glm::translate(model, glm::vec3(pos, 0.0f));
	
	
	// rotate (move origin to center, rotate, move origin back)
	model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
	model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
	model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));
	
	// scale
	model = glm::scale(model, glm::vec3(size, 1.0f));
	shader.uniformMat4("model", model);
		
	shader.uniformVec3("spriteColor", color);
	

	glActiveTexture(GL_TEXTURE0);
	texture.bind();

	// render textured quad
	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
}



void SpriteRenderer::init()
{
	GLuint VBO, EBO;
	GLfloat vertices[] = {
		// Pos      // Tex
		0.0f, 1.0f, 0.0f, 1.0f, // Top Left
		0.0f, 0.0f, 0.0f, 0.0f, // Bottom Left
		1.0f, 1.0f, 1.0f, 1.0f, // Top Right
		1.0f, 0.0f, 1.0f, 0.0f, // Bottom Right
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
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);

	glBindVertexArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

}
