#include "Entity.h"



Entity::Entity(Texture2D& texture, glm::vec2 pos, glm::vec2 size, glm::vec3 color, GLfloat rot, glm::vec2 vel)
	: GameObject(texture, pos, size, color, rot),
	vel( vel )
{
}