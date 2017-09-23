#pragma once
#include "Component.h"
#include <glm/glm.hpp>

class PosComponent :
	public Component
{
private:
	glm::vec3 pos;

public:
	PosComponent();
	~PosComponent();

	void test();
};

