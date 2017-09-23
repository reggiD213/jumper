#include "Block.h"

Block::Block(char code, Texture2D& texture, glm::vec2 pos, glm::vec2 size, glm::vec3 color, GLfloat rot)
	: GameObject(texture, pos, size, color, rot), code(code)
{
}