#pragma once
#include "Entity.h"
class Block :
	public Entity
{
private:

public:
	char code;
	Block(char code, glm::vec2 pos, glm::vec2 size, glm::vec2 vel, glm::vec3 color, GLfloat rot, Texture2D& texture);

	void update(float dt) override;

	void run(bool on = true) override {}

	void setForceDirection(Direction dir) override {}
};

