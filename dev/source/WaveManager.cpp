#include "WaveManager.hpp"
#include <iostream>

WaveManager::WaveManager(){

}

WaveManager::WaveManager(int fase, float screen_x, float screen_y, CollisionManager * cManager, tmx::MapLoader * mapLoader, Display * dis){
	waveAtual = 0;
	
	switch(fase){
		case 1:
			faseAtual = 1;	
			
			for(int i = 1; i < 6; i++){
				Wave * newWave = new Wave(i, screen_x, screen_y, cManager, mapLoader, dis);
				wavesFase.push_back(newWave);
			}			
			
		break;

		case 2:
			faseAtual = 2;
			
			for(int i = 6; i < 11; i++){
				Wave * newWave = new Wave(i, screen_x, screen_y, cManager, mapLoader, dis);
				wavesFase.push_back(newWave);
			}	
			
		break;

		default:
			std::cout <<"Fase Invalida"<<std::endl;
		break;
	}
}

// Wave WaveManager::getWave(int waveId){
// 	return wavesFase[waveId];
// }

std::vector<CharEnemmy *> WaveManager::getWaveEnemmyList(int waveId){
	waveAtual = waveId;
	return wavesFase[waveId-1]->getWaveEnemmies();
}

// std::vector<int> WaveManager::getWaveEnemmyListId(int waveId){
// 	return wavesFase[waveId].getIdColisionObjects();
// }

//getters and setters
void WaveManager::setFaseAtual(int fAtu){
  faseAtual = fAtu;
}

void WaveManager::setWaveAtual(int wAtu){
  waveAtual = wAtu;
}
//------------------
int WaveManager::getFaseAtual(){
  return faseAtual;
}
int WaveManager::getWaveAtual(){
  return waveAtual;
}
