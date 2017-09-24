#pragma once

#include <string>
#include <vector>

#include "TextRenderer.h"
#include "RectRenderer.h"
#include "GameObject.h"
#include "Player.h"
#include "Rect.h"

class Debugger
{
public:
	Debugger();
private:

	std::string fpsInfo;
	std::string playerInfo;
	std::string boundingInfo;

	float timer;

	const glm::vec4 boundingBoxColor = glm::vec4(1.0f, 0.0f, 0.0f, 0.5f);;

	std::vector<Rect> boundingBoxes;

public:
	void draw(RectRenderer& rectRenderer, TextRenderer& textRenderer, int width, int height);
	void update(float dt, Player& player, std::vector<GameObject> gameObjects);
	
	bool debugFps;
	bool debugPlayer;
	bool debugBounding;
};

