#pragma once

#include <string>
#include <vector>
#include <memory>
#include "Entity.h"
#include "Block.h"
#include "SpriteRenderer.h"

class Level
{
private:
	std::string levelString;

	int width;
	int height;
public:
	Level();
	~Level();

	void create(const std::string& levelString, int width, int height);
	void createGameObjects();

	void update();

	void draw(SpriteRenderer& renderer);

	std::string getLevelString();
	std::vector<std::shared_ptr<Block>> blocks;
};

