#include <SFML/Graphics.hpp>
#include "World.cpp"
#include "gameTile.cpp"
#include "constantes.h"
#include <iostream>




int main()
{
	int parse = 0;
	
	sf::RenderWindow window(sf::VideoMode(500, 500), "Mario Sokoban demo de l'apha de la beta");

	GameWorld gameWorld = GameWorld();

	sf::Texture texture;
	if (!texture.loadFromFile("Images/menu.jpg")) {
		return 0;
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);

	sf::Texture text;
	if (!texture.loadFromFile("Images/mario_bas.gif")) {

		return 0;
	}

	sf::Sprite perso;
	perso.setTexture(text);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
				if(event.type == sf::Event::Closed)
					window.close();
				if(event.type == sf::Event::KeyPressed && parse == 0){
					if (event.key.code == sf::Keyboard::S)
						parse = 1;
					if (event.key.code == sf::Keyboard::Escape) {
						window.close();
						break;
					}
				}
			if(parse == 0)
				window.draw(sprite);
			if(parse == 1){
				window.draw(perso);
			}
			window.display();
			window.clear();
		}
		/*for (int i = 0; i < gameWorld.gridLenght; i++) {
			for (int j = 0; j <gameWorld.gridLenght; j++) {
				window.draw(gameWorld.tiles[i][j]->sprite);
			}
		}*/
	}

}