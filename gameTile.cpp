#include "gameTile.h"

GameTile::GameTile(std::string textureName, float x, float y, bool passable, bool exit)
{
	if (!setUpSprite(textureName))
	{
		return;
	}
	pos = sf::Vector2f(x, y);
	sprite.setPosition(pos);
	isPassable = passable;
	isExit = exit;
}



bool GameTile::setUpSprite(std::string textureName)
{
	if (!texture.loadFromFile(textureName))
	{
		return false;
	}
	texture.setSmooth(true);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0,0,50,50));

	return true;
}

