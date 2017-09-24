#include "GameObject.h"

#include <iostream>

GameObject::GameObject(Texture2D& texture, glm::vec2 pos, glm::vec2 size, glm::vec3 color, GLfloat rot)
	: texture{ texture },
	  pos{ pos },
	  size{ size },
	  color{ color },
	  rot{ rot }
{
}

void GameObject::draw(SpriteRenderer& renderer)
{
	renderer.drawSprite(texture, pos, size, rot, color);
}

