#pragma once

#include <GL/glew.h>

class Texture2D
{
public:
	Texture2D();
	~Texture2D();
	void create(GLuint width, GLuint height, unsigned char* image, GLuint intFormat = GL_RGB, GLuint imgFormat = GL_RGB, GLuint wrapS = GL_REPEAT, GLuint wrapT = GL_REPEAT, GLuint filterMin = GL_LINEAR, GLuint filterMag = GL_LINEAR);
	void bind() const;
private:
	GLuint ID;
	GLuint width{ 0 }, height{ 0 };
};

