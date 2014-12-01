#ifndef GUNMANAGER_HPP
#define GUNMANAGER_HPP

#include <vector>
#include <fstream> 
#include <string>
#include "Gun.hpp"

class GunManager {   
private:
   std::vector<Gun> gunVector;
   std::vector<std::string> gunAudio;
public:
   GunManager();

   Gun getGun(int id);

   std::string getAudio(int id);
};

#endif