#ifndef WAVE_HPP
#define WAVE_HPP

#include "CharEnemmy.hpp"
#include "Display.hpp"
#include <iostream>
#include <vector>

class Wave{
  int idWave;
  std::vector<CharEnemmy *> waveEnemmies;

public:
  Wave();
  ~Wave();
  Wave(int waveNum, float screen_x, float screen_y, CollisionManager * cManager, tmx::MapLoader * mapLoader, Display * dis);

  //getters and setters
  void setIdWave(int neWaveId);
  //-------------------
  int getIdWave(int neWaveId);
  std::vector<CharEnemmy *> getWaveEnemmies();
  
  // std::vector<int> getIdColisionObjects();
};

#endif
