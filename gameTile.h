#pragma once
#include <SFML/Graphics.hpp>

#ifndef GAMETILE_H
#define GAMETILE_H

class GameTile {
public:
	bool isPassable;
	bool isExit;

	sf::Vector2f pos;
	sf::Texture texture;
	sf::Sprite sprite;

	GameTile(std::strig, float, float, bool, bool);
	bool setUpSprite(std::string);
};

#endif