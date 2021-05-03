#include <SFML/Graphics.hpp>
#include "World.cpp"
#include "gameTile.cpp"
#include <iostream>


int main()
{
	
	sf::RenderWindow window(sf::VideoMode(800, 600), "Mario Sokoban demo de l'apha de la beta");

	GameWorld gameWorld = GameWorld();

	sf::Texture texture;
	if (!texture.loadFromFile("Images/objectif.jpg")) {
		return 0;
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
		}
		window.clear();

		for (int i = 0; i < gameWorld.gridLenght; i++) {
			for (int j = 0; j <gameWorld.gridLenght; j++) {
				window.draw(gameWorld.tiles[i][j]->sprite);
			}
		}
		window.display();
	}
}