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

void Level::create(const std::string& levelString, int width, int height) 
{
	this->levelString = levelString;
	this->width = width;
	this->height = height;
}

void Level::createGameObjects()
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
		std::shared_ptr<Block> block = std::make_shared<Block>(Block(c, ResourceManager::getTexture(textureName), { x * width, y * height }, { width,height }));
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

}

void Level::draw(SpriteRenderer& renderer)
{
	for (auto block : blocks)
	{
		block->draw(renderer);
	}
}
