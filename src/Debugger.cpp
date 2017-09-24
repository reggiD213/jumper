#include "Debugger.h"

#include <sstream>

Debugger::Debugger()
	: debugFps(false),
	  debugPlayer(false),
	  debugBounding(false),
	  timer(0.0f)
{
}

void Debugger::update(float dt, Player& player, std::vector<GameObject> gameObjects)
{
	timer += dt;
	if (timer > 0.25f)
	{
		if (debugFps)
		{
			float fps = 1 / dt;
			std::stringstream ss;
			ss << fps;
			fpsInfo = ss.str();

		}
		if (debugPlayer) // heavy performance impact
		{
			std::stringstream ss;
			ss << "Debuginfo: " << player;
			playerInfo = ss.str();
		}
		if (debugBounding)
		{
			boundingBoxes.clear();
			boundingBoxes.push_back(player.boundingBox);
			for (auto& gameObject : gameObjects)
				boundingBoxes.push_back(gameObject.boundingBox);
		}
		timer = 0.0f;
	}
}

void Debugger::draw(RectRenderer& rectRenderer, TextRenderer& textRenderer, int width, int height)
{
	if (debugFps)
		textRenderer.RenderText(fpsInfo, width - 100.0f, 3.0f, 1.0f);
	if (debugPlayer)
		textRenderer.RenderText(playerInfo, 3.0f, 3.0f, 1.0f);
	if (debugBounding)
		for (auto& rect : boundingBoxes)
			rectRenderer.drawRect(rect, boundingBoxColor);
		
}
