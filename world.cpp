#include "world.h"


GameWorld::GameWorld(){
	gridLenght = 8;
	setUpInitialState();

	}


void GameWorld::setUpInitialState() {
	exitPos = sf::Vector2i(1, 0);
	playerPos = sf::Vector2i(gridLenght-1, gridLenght-1);
	setUpTiles();
}


void GameWorld::setUpTiles() {
	tiles.clear();
	std::vector<GameTile *> firstRow;
	firstRow.push_back(new GameTile("Images/mur.jpg", 0,0,false,false));
	firstRow.push_back(new GameTile("Images/caisse.jpg", 50, 0, true, true));
	firstRow.push_back(new GameTile("Images/mur.jpg", 50, 0, false, false));
	firstRow.push_back(new GameTile("Images/mur.jpg", 100, 0, false, false));
	firstRow.push_back(new GameTile("Images/mur.jpg", 150, 0, false, false));
	firstRow.push_back(new GameTile("Images/mur.jpg", 200, 0, false, false));
	firstRow.push_back(new GameTile("Images/mur.jpg", 250, 0, false, false));
	firstRow.push_back(new GameTile("Images/mario_bas.gif", 300, 0, true, false));
	firstRow.push_back(new GameTile("Images/mur.jpg", 350, 0, false, false));
	tiles.push_back(firstRow);

	std::vector<GameTile *> secondRow;
	secondRow.push_back(new GameTile("Images/mur.jpg", 0, 50, false, false));
	secondRow.push_back(new GameTile("Images/objectif.png", 0, 50, true, false));
	secondRow.push_back(new GameTile("Images/caisse_ok.jpg", 50, 50, true, false));
	secondRow.push_back(new GameTile("Images/caisse_ok.jpg", 100, 50, true, false));
	secondRow.push_back(new GameTile("Images/caisse_ok.jpg", 150, 50, true, false));
	secondRow.push_back(new GameTile("Images/caisse_ok.jpg", 200, 50, true, false));
	secondRow.push_back(new GameTile("Images/caisse_ok.jpg", 250, 50, true, false));
	secondRow.push_back(new GameTile("Images/mario_bas.gif", 300, 50, true, false));
	secondRow.push_back(new GameTile("Images/caisse_ok.jpg", 350, 50, true, false));
	tiles.push_back(secondRow);

	std::vector<GameTile *> thirdRow;
	thirdRow.push_back(new GameTile("Images/mur.jpg", 0, 100, false, false));
	thirdRow.push_back(new GameTile("Images/objectif.png", 0, 100, true, false));
	thirdRow.push_back(new GameTile("Images/caisse_ok.jpg", 50, 100, true, false));
	thirdRow.push_back(new GameTile("Images/caisse_ok.jpg", 100, 100, true, false));
	thirdRow.push_back(new GameTile("Images/caisse_ok.jpg", 150, 100, true, false));
	thirdRow.push_back(new GameTile("Images/objectif.png", 200, 100, true, false));
	thirdRow.push_back(new GameTile("Images/caisse_ok.jpg", 250, 100, true, false));
	thirdRow.push_back(new GameTile("Images/caisse_ok.jpg", 300, 100, true, false));
	thirdRow.push_back(new GameTile("Images/caisse_ok.jpg", 350, 100, true, false));
	tiles.push_back(thirdRow);

	std::vector<GameTile *> fourthRow;
	fourthRow.push_back(new GameTile("Images/mur.jpg", 0, 150, false, false));
	fourthRow.push_back(new GameTile("Images/caisse_ok.jpg", 0, 150, true, false));
	fourthRow.push_back(new GameTile("Images/caisse_ok.jpg", 50, 150, true, false));
	fourthRow.push_back(new GameTile("Images/caisse_ok.jpg", 100, 150, true, false));
	fourthRow.push_back(new GameTile("Images/caisse_ok.jpg", 150, 150, true, false));
	fourthRow.push_back(new GameTile("Images/caisse_ok.jpg", 200, 150, true, false));
	fourthRow.push_back(new GameTile("Images/caisse_ok.jpg", 250, 150, true, false));
	fourthRow.push_back(new GameTile("Images/caisse_ok.jpg", 300, 150, true, false));
	fourthRow.push_back(new GameTile("Images/caisse_ok.jpg", 350, 150, true, false));
	tiles.push_back(fourthRow);

	std::vector<GameTile *> fifthRow;
	fifthRow.push_back(new GameTile("Images/mur.jpg", 0, 200, false, false));
	fifthRow.push_back(new GameTile("Images/caisse_ok.jpg", 0, 200, true, false));
	fifthRow.push_back(new GameTile("Images/caisse_ok.jpg", 50, 200, true, false));
	fifthRow.push_back(new GameTile("Images/caisse_ok.jpg", 100, 200, true, false));
	fifthRow.push_back(new GameTile("Images/caisse_ok.jpg", 150, 200, true, false));
	fifthRow.push_back(new GameTile("Images/caisse_ok.jpg", 200, 200, true, false));
	fifthRow.push_back(new GameTile("Images/caisse_ok.jpg", 250, 200, true, false));
	fifthRow.push_back(new GameTile("Images/caisse_ok.jpg", 300, 200, true, false));
	fifthRow.push_back(new GameTile("Images/caisse_ok.jpg", 350, 200, true, false));
	tiles.push_back(fifthRow);

	std::vector<GameTile *> sixthRow;
	sixthRow.push_back(new GameTile("Images/mur.jpg", 0, 250, false, false));
	sixthRow.push_back(new GameTile("Images/caisse_ok.jpg", 0, 250, true, false));
	sixthRow.push_back(new GameTile("Images/caisse_ok.jpg", 50, 250, true, false));
	sixthRow.push_back(new GameTile("Images/caisse_ok.jpg", 100, 250, true, false));
	sixthRow.push_back(new GameTile("Images/caisse_ok.jpg", 150, 250, true, false));
	sixthRow.push_back(new GameTile("Images/caisse_ok.jpg", 200, 250, true, false));
	sixthRow.push_back(new GameTile("Images/caisse_ok.jpg", 250, 250, true, false));
	sixthRow.push_back(new GameTile("Images/caisse_ok.jpg", 300, 250, true, false));
	sixthRow.push_back(new GameTile("Images/caisse_ok.jpg", 350, 250, true, false));
	tiles.push_back(sixthRow);
}