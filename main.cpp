#include <SFML/Graphics.hpp>
#include <iostream>


int main()
{
	// création de la fenêtre
	sf::RenderWindow window(sf::VideoMode(800, 600), "Mario Sokoban demo de l'apha de la beta");

	sf::Texture texture;
	if(!texture.loadFromFile("sprites-sokoban-2021/mario_bas.gif"))
	{
		return 0;
	}
	sf::Sprite sprite;
	sprite.setTexture(texture);

	// on fait tourner le programme tant que la fenêtre n'a pas été fermée
	while (window.isOpen())
	{
		// on traite tous les évènements de la fenêtre qui ont été générés depuis la dernière itération de la boucle
		sf::Event event;
		while (window.pollEvent(event))
		{
			// fermeture de la fenêtre lorsque l'utilisateur le souhaite
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// effacement de la fenêtre en noir
		window.clear(sf::Color::Black);

		// c'est ici qu'on dessine tout
		//window.draw(sprite);

		// fin de la frame courante, affichage de tout ce qu'on a dessiné
		window.display();
	}

	return 0;
}