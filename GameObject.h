#pragma once

#include <vector>
#include <map>
#include <string>
#include "Component.h"

class GameObject
{
public:
	GameObject();
	~GameObject();

private:
	std::map<std::string, Component*> components;
};

