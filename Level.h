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

	static constexpr int width = 40;
	static constexpr int height = 40;
public:
	Level();
	~Level();

	void create(const std::string& levelString);
	void createEntities();

	void update();

	void draw(SpriteRenderer& renderer);

	std::string getLevelString();
	std::vector<std::shared_ptr<Block>> blocks;
};

