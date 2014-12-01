#ifndef GUNMANAGER_HPP
#define GUNMANAGER_HPP

#include <vector>
#include <fstream> 
#include <SFML/Audio/Sound.hpp> 
#include <SFML/Audio/SoundBuffer.hpp> 
#include "Gun.hpp"

class GunManager {   
private:
   std::vector<Gun> gunVector;
   std::vector<sf::SoundBuffer> gunAudio;
public:
   GunManager();

   Gun getGun(int id);

   sf::Sound getAudio(int id);
};

#endif