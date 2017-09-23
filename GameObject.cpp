#include "GameObject.h"
#include "PosComponent.h"

GameObject::GameObject()
{
	components["pos"] = {};
	((PosComponent*)components["pos"])->test();
}

GameObject::~GameObject()
{
}