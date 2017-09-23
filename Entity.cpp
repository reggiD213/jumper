#include "Entity.h"



Entity::Entity(glm::vec2 pos, glm::vec2 size, glm::vec2 vel, glm::vec3 color, GLfloat rot, Texture2D& texture)
	: pos{ pos },
	  size{ size },
	  vel{ vel },
	  color{ color },
	  rot{ rot },
	  texture{ texture }
{
}


void Entity::draw(SpriteRenderer& renderer)
{
	renderer.drawSprite(texture, pos, size, rot, color);
}
