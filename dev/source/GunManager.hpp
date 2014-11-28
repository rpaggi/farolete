#ifndef GUNMANAGER_HPP
#define GUNMANAGER_HPP

#include <vector>
#include <fstream> 
#include <SFML/Audio/Music.hpp> 
#include "Gun.hpp"

class GunManager {   
private:
   std::vector<Gun> gunVector;
   std::vector<sf::Music *> gunAudio;
public:
   GunManager();

   Gun getGun(int id);

   sf::Music * getAudio(int id);
};

#endif