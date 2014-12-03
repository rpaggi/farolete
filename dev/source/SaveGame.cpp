#include "SaveGame.hpp"

SaveGame::SaveGame(){
	stage   = 0;
	wave    = 0;
	gunId   = 0;
	hp      = 0;
	stamina = 0;
	xp      = 0;
	bullets = 0;
}

void SaveGame::loadGame(){
	std::ifstream fin("savegame.dat", std::ofstream::binary);
	fin.read((char *)this, sizeof(SaveGame));
	fin.close();
}

void SaveGame::saveGame(){
	std::ofstream fout("savegame.dat", std::ofstream::binary);
	fout.write((char *)this, sizeof(SaveGame));
	fout.close();
}

void SaveGame::display(){
	std::cout<<"Stage..:"<<stage<<std::endl;
	std::cout<<"Wave...:"<<wave<<std::endl;
	std::cout<<"gunId..:"<<gunId<<std::endl;
	std::cout<<"HP.....:"<<hp<<std::endl;
	std::cout<<"Stamina:"<<stamina<<std::endl;
	std::cout<<"Bullets:"<<bullets<<std::endl;
	std::cout<<"Xp.....:"<<xp<<std::endl;
}