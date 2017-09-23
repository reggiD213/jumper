#include "Texture2D.h"

#include <iostream>

Texture2D::Texture2D()
{
	// create Texture and retrieve ID
	glGenTextures(1, &ID);
}

Texture2D::~Texture2D()
{
	// clean up
	std::cout << ID << " deleted" << std::endl;
	glDeleteTextures(1, &ID);
}

void Texture2D::create(GLuint width, GLuint height, unsigned char* image, GLuint intFormat, GLuint imgFormat, GLuint wrapS, GLuint wrapT, GLuint filterMin, GLuint filterMag)
{
	this->width = width;
	this->height = height;
	glBindTexture(GL_TEXTURE_2D, this->ID);
	glTexImage2D(GL_TEXTURE_2D, 0, intFormat, width, height, 0, imgFormat, GL_UNSIGNED_BYTE, image);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapS);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filterMin);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filterMag);
	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture2D::bind() const
{
	glBindTexture(GL_TEXTURE_2D, ID);
}
