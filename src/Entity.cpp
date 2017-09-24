#include "Entity.h"

Entity::Entity(Texture2D& texture, glm::vec2 pos, glm::vec2 size, glm::vec3 color, GLfloat rot, glm::vec2 vel)
	: GameObject(texture, pos, size, color, rot),
	vel(vel),
	standing(false)
{
}

std::ostream& operator<<(std::ostream& out, const Entity& e)
{
	out << "\npos x: " << e.pos.x << " | y: " << e.pos.y
		<< "\nvel x: " << e.vel.x << " | y: " << e.vel.y
		<< "\nacc x: " << e.acc.x << " | y: " << e.acc.y
		<< "\nStanding: " << e.standing;
	return out;
}

Rect::Side Entity::collision(const GameObject& object)
{
	return boundingBox.collision(object.boundingBox);
}