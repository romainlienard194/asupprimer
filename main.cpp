#include <SFML/Graphics.hpp>
#include <iostream>

#include "constantes.h"
#include "jeu.h"
#include "editeur.h"

using namespace std;

int main(int argc, char **argv)
{
	sf::Window window(sf::VideoMode(800, 600), "Ma fen�tre swaggy");

	// on fait tourner le programme jusqu'� ce que la fen�tre soit ferm�e
	while (window.isOpen())
	{
		// on inspecte tous les �v�nements de la fen�tre qui ont �t� �mis depuis la pr�c�dente it�ration
		sf::Event event;
		while (window.pollEvent(event))
		{
			// �v�nement "fermeture demand�e" : on ferme la fen�tre
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
	}

	return 0;
}