#include "Rect.h"



Rect::Rect()
{
}


Rect::~Rect()
{
}

Rect::Side Rect::collision(const Rect& other)
{
	if (!(pos.x <= other.pos.x + other.size.x &&
		  pos.x + size.x >= other.pos.x &&
		  pos.y <= other.pos.y + other.size.y &&
		  pos.y + size.y >= other.pos.y))
		// no collision
		return Side::None;
	else if (pos.y + size.y <= other.pos.y + 5)
		// top collision
		return Side::Top;
	else if (pos.y >= other.pos.y + other.size.y - 5)
		// bottom collision
		return Side::Bottom;
	else if (pos.x <= other.pos.x + other.size.y / 2)
		// left collision
		return Side::Left;
	else
		return Side::Right;
}