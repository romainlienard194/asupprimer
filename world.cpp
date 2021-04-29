#include "world.h"

world::world() {
	gridLenght = 8;
	seUpInitialState();
}

void world::setUpInitlaState() {
	exitPos = sf::vector2i(1, 0);
	playerPos = sf::vector2i(gridLenght-1, gridLenght-1);
	setUpBlockPositions();
	setUpTile();
}

void world::setUpBlockPosition{
	blockPositions.clear();
	blockPositions.push_back(sf::Vector2i(0, 2));
	blockPositions.push_back(sf::Vector2i(6, 0));
	blockPositions.push_back(sf::Vector2i(2, 7));
}

void world::setUpTile{

}