#include <SFML/Graphics.hpp>
#include "constantes.h"
#include "jeu.h"
#include "editeur.h"


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


	int main(int argc, char *argv[])
{
	SDL_Surface *ecran = NULL, *menu = NULL;
	SDL_Rect positionMenu;
	SDL_Event event;

	int continuer = 1;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_WM_SetIcon(IMG_Load("caisse.jpg"), NULL); // L'ic�ne doit �tre charg�e avant SDL_SetVideoMode
	ecran = SDL_SetVideoMode(LARGEUR_FENETRE, HAUTEUR_FENETRE, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
	SDL_WM_SetCaption("Mario Sokoban", NULL);

	menu = IMG_Load("menu.jpg");
	positionMenu.x = 0;
	positionMenu.y = 0;

	while (continuer)
	{
		SDL_WaitEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			continuer = 0;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE: // Veut arr�ter le jeu
				continuer = 0;
				break;
			case SDLK_KP1: // Demande � jouer
				jouer(ecran);
				break;
			case SDLK_KP2: // Demande l'�diteur de niveaux
				editeur(ecran);
				break;
			}
			break;
		}

		// Effacement de l'�cran
		SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 0, 0, 0));
		SDL_BlitSurface(menu, NULL, ecran, &positionMenu);
		SDL_Flip(ecran);
	}

	SDL_FreeSurface(menu);
	SDL_Quit();

	return EXIT_SUCCESS;
}