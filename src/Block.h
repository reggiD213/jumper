#pragma once
#include "Entity.h"
class Block :
	public GameObject
{
private:

public:
	char code;
	Block(char code, Texture2D& texture, glm::vec2 pos, glm::vec2 size, glm::vec3 color = { 1, 1, 1 }, GLfloat rot = 0.0f);

};