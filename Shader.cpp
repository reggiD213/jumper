#include "Shader.h"

#include <iostream>

#include <glm/gtc/type_ptr.hpp>

Shader::~Shader()
{
	// clean up
	std::cout << ID << " deleted" << std::endl;
	glDeleteProgram(ID);
}

void Shader::create(const char* vertexSource, const char* fragmentSource, const char* geometrySource)
{
	GLuint sVertex, sFragment, sGeometry;
	// Vertex
	sVertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(sVertex, 1, &vertexSource, 0);
	glCompileShader(sVertex);
	checkForErrors(sVertex, "VERTEX");
	// Fragment
	sFragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(sFragment, 1, &fragmentSource, 0);
	glCompileShader(sFragment);
	checkForErrors(sFragment, "FRAGMENT");
	// Geometry (optional)
	if (geometrySource != nullptr)
	{
		sGeometry = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(sGeometry, 1, &geometrySource, 0);
		glCompileShader(sGeometry);
		checkForErrors(sGeometry, "GEOMETRY");
	}
	// Link Program
	ID = glCreateProgram();
	glAttachShader(ID, sVertex);
	glAttachShader(ID, sFragment);
	if (geometrySource != nullptr)
		glAttachShader(ID, sGeometry);
	glLinkProgram(ID);
	checkForErrors(ID, "PROGRAM");
	// CleanUp
	glDeleteShader(sVertex);
	glDeleteShader(sFragment);
	if (geometrySource != nullptr)
		glDeleteShader(sGeometry);
}

Shader& Shader::use()
{
	glUseProgram(ID);
	return *this;
}

void Shader::uniformFloat(const char* name, GLfloat value)
{
	glUniform1f(glGetUniformLocation(ID, name), value);
}

void Shader::uniformInt(const char* name, GLint value)
{
	glUniform1i(glGetUniformLocation(ID, name), value);
}

void Shader::uniformVec2(const char* name, GLfloat x, GLfloat y)
{
	glUniform2f(glGetUniformLocation(ID, name), x, y);
}

void Shader::uniformVec2(const char* name, const glm::vec2& value)
{
	glUniform2f(glGetUniformLocation(ID, name), value.x, value.y);
}

void Shader::uniformVec3(const char*  name, GLfloat x, GLfloat y, GLfloat z)
{
	glUniform3f(glGetUniformLocation(ID, name), x, y, z);
}

void Shader::uniformVec3(const char* name, const glm::vec3& value)
{
	glUniform3f(glGetUniformLocation(ID, name), value.x, value.y, value.z);
}

void Shader::uniformVec4(const char* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w)
{
	glUniform4f(glGetUniformLocation(ID, name), x, y, z, w);
}

void Shader::uniformVec4(const char* name, const glm::vec4& value)
{
	glUniform4f(glGetUniformLocation(ID, name), value.x, value.y, value.z, value.w);
}

void Shader::uniformMat4(const char* name, const glm::mat4& value)
{
	glUniformMatrix4fv(glGetUniformLocation(ID, name), 1, GL_FALSE, glm::value_ptr(value));
}

void Shader::checkForErrors(GLuint shaderID, const char* type)
{
	GLint success;
	GLchar infoLog[1024];

	if (type == "PROGRAM")
	{
		glGetProgramiv(shaderID, GL_LINK_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shaderID, 1024, 0, infoLog);
			std::cout << "Shader Linking error: Type: " << type << "\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetProgramInfoLog(shaderID, 1024, 0, infoLog);
			std::cout << "Shader Compile error: Type: " << type << "\n" << infoLog << std::endl;
		}
	}
}
