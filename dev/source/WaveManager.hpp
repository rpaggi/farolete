#ifndef WAVEMANAGER_HPP
#define WAVEMANAGER_HPP

#include "Wave.hpp"
#include <vector>

class WaveManager{
  int                          faseAtual;
  int                          waveAtual;
  std::vector<Wave *>          wavesFase;
  
public:
  WaveManager(); 
  ~WaveManager(); 
  WaveManager(int fase, float screen_x, float screen_y, CollisionManager * cManager, tmx::MapLoader * mapLoader, Display * dis);   
  // Wave *                       getWave(int waveId);
  std::vector<CharEnemmy *>    getWaveEnemmyList(int waveId);
  // std::vector<int>             getWaveEnemmyListId(int waveId);    
  
  //getters and setters
  void setFaseAtual(int fAtu);
  void setWaveAtual(int wAtu);
  //------------------
  int getFaseAtual();
  int getWaveAtual();
  
};

#endif