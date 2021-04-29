#include <SFML/Graphics.hpp>
#include "gameTile.h"
#include <vector>

#ifndef GAMETILE_H
#define GAMETILE_H

class world {
	sf::Vector2i exitPos;
	sf::Vector2i playerPos;
	sf::vector<sf::Vector2i> blockPos;
	void setUpInitialState();
	void setUpBlockPositions();
	void setUpTiles();

public:
	std::vector< std::vector<GameTile *> > tiles;
	int gridLenght;

	world();
};

#endif