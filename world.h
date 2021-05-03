#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>

#ifndef WORLD_H
#define WORLD_H

class GameWorld {
	sf::Vector2i exitPos;
	sf::Vector2i playerPos;
	void setUpInitialState();
	void setUpTiles();

public:
	std::vector< std::vector<GameTile *> > tiles;
	int gridLenght;

	GameWorld();
};

#endif