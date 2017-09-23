#pragma once

#include <map>

#include "Texture2D.h"
#include "Shader.h"
#include "Level.h"

class ResourceManager
{
public:
	static Texture2D& createTexture(const char* name, const char* file, bool alpha = false);
	static Texture2D& getTexture(const char* name);

	static Shader& createShader(const char* name, const char* vertexShaderFile, const char* fragmentShaderFile, const char* geometryShaderFile = nullptr);
	static Shader& getShader(const char* name);

	static Level& createLevel(const char* name, const char* file);
	static Level& getLevel(const char* name);

private:
	// Static class
	ResourceManager() {}
	// Storage
	static std::map<const char*, Texture2D> textures;
	static std::map<const char*, Shader> shaders;
	static std::map<const char*, Level> levels;
};

