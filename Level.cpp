#include "Level.h"
#include "ResourceManager.h"
#include "Block.h"
#include <iostream>

Level::Level()
{
}


Level::~Level()
{
}

void Level::create(const std::string& levelString) 
{
	this->levelString = levelString;
}

void Level::createEntities()
{
	int x = 0;
	int y = 0;

	for (auto c : levelString)
	{
		const char* textureName = "";
		switch (c)
		{
		case '#':
			textureName = "brick";
			break;
		case 'L':
			textureName = "grassLeft";
			break;
		case 'M':
			textureName = "grassMiddle";
			break;
		case 'R':
			textureName = "grassRight";
			break;
		case 'G':
			textureName = "grass";
			break;
		case ' ':
			x++;
			continue;
		case '\n':
			x = -1;
			y++;
			break;
		default:
			textureName = "invalid";
			break;
		}
		std::shared_ptr<Block> block = std::make_shared<Block>(Block(c, ResourceManager::getTexture(textureName), { x * width, y * height }, { width,height }, { 1,1,1 }, 0.0f));
		blocks.push_back(block);
		x++;
	}

}

std::string Level::getLevelString()
{
	return levelString;
}

void Level::update()
{
	for (auto block : blocks)
	{
		for (int x = -width; x <= width; x += width)
		{
			for (int y = -height; y <= height; y += height)
			{

			}
		}
	}
}

void Level::draw(SpriteRenderer& renderer)
{
	for (auto block : blocks)
	{
		block->draw(renderer);
	}
}
