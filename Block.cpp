#include "Block.h"

Block::Block(char code, glm::vec2 pos, glm::vec2 size, glm::vec2 vel, glm::vec3 color, GLfloat rot, Texture2D& texture)
	: Entity(pos, size, vel, color, rot, texture), code(code)
{

}

void Block::update(float dt)
{

}
