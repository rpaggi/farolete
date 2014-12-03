#ifndef SAVEGAME_HPP
#define SAVEGAME_HPP

#include <fstream> 
#include <iostream>

class SaveGame
{
public:
	int stage;
	int wave;
	int gunId;
	int hp;
	int stamina;
	int xp;
	int bullets;

	SaveGame();

	void loadGame();
	void saveGame();
	void display();
};

#endif