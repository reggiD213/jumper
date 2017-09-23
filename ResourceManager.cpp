#include "ResourceManager.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include <SOIL/SOIL.h>

std::map<const char*, Texture2D> ResourceManager::textures;
std::map<const char*, Shader> ResourceManager::shaders;
std::map<const char*, Level> ResourceManager::levels;

Texture2D& ResourceManager::createTexture(const char* name, const char* file, bool alpha)
{
	int width, height;
	unsigned char* image;

	if (alpha)
	{
		image = SOIL_load_image(file, &width, &height, 0, SOIL_LOAD_RGBA);
		textures[name].create(width, height, image, GL_RGBA, GL_RGBA);
	}
	else
	{
		image = SOIL_load_image(file, &width, &height, 0, SOIL_LOAD_RGB);
		textures[name].create(width, height, image);
	}

	SOIL_free_image_data(image);
	return textures[name];
}

Texture2D& ResourceManager::getTexture(const char* name)
{
	return textures[name];
}

Shader& ResourceManager::createShader(const char* name, const char* vertexShaderFile, const char* fragmentShaderFile, const char* geometryShaderFile)
{
	
	// Read files to string
	std::string vertexShaderString;
	std::string fragmentShaderString;
	std::string geometryShaderString;
	
	try {
		// Vertex
		std::ifstream vertexShaderStream(vertexShaderFile);
		std::stringstream vertexShaderStringStream;
		vertexShaderStringStream << vertexShaderStream.rdbuf();
		vertexShaderStream.close();
		vertexShaderString = vertexShaderStringStream.str();
		// Fragment
		std::ifstream fragmentShaderStream(fragmentShaderFile);
		std::stringstream fragmentShaderStringStream;
		fragmentShaderStringStream << fragmentShaderStream.rdbuf();
		fragmentShaderStream.close();
		fragmentShaderString = fragmentShaderStringStream.str();
		// Geometry
		if (geometryShaderFile != nullptr)
		{
			std::ifstream geometryShaderStream(geometryShaderFile);
			std::stringstream geometryShaderStringStream;
			geometryShaderStringStream << geometryShaderStream.rdbuf();
			geometryShaderStream.close();
			geometryShaderString = geometryShaderStringStream.str();
		}
	}
	catch (std::exception e)
	{
		std::cout << "Error failed to open/read shader files" << std::endl;
	}
		
	const GLchar* vertexShaderCString = vertexShaderString.c_str();
	const GLchar* fragmentShaderCString = fragmentShaderString.c_str();
	const GLchar* geometryShaderCString = geometryShaderString.c_str();

	shaders[name].create(vertexShaderCString, fragmentShaderCString, geometryShaderFile != nullptr ? geometryShaderCString : nullptr);
	return shaders[name];
}

Shader& ResourceManager::getShader(const char* name)
{
	return shaders[name];
}

Level& ResourceManager::createLevel(const char* name, const char* file)
{
	std::ifstream levelFile(file);
	std::stringstream levelStringStream;
	levelStringStream << levelFile.rdbuf();
	levelFile.close();
	levels[name].create(levelStringStream.str());
	return levels[name];
}

Level& ResourceManager::getLevel(const char* name)
{
	return levels[name];
}
