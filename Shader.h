#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>

class Shader
{
public:
	Shader() {}
	~Shader();
	void create(const char* vertexSource, const char* fragmentSource, const char* geometrySource = nullptr);
	Shader& use();
	// uniform helpers
	void uniformFloat(const char* name, GLfloat value);
	void uniformInt(const char* name, GLint value);
	void uniformVec2(const char* name, GLfloat x, GLfloat y);
	void uniformVec2(const char* name, const glm::vec2& value);
	void uniformVec3(const char* name, GLfloat x, GLfloat y, GLfloat z);
	void uniformVec3(const char* name, const glm::vec3& value);
	void uniformVec4(const char* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w);
	void uniformVec4(const char* name, const glm::vec4& value);
	void uniformMat4(const char* name, const glm::mat4& value);

	GLuint ID;
private:

	void checkForErrors(GLuint shaderID, const char* type);
};

