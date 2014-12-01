#include "GunManager.hpp"
#include <iostream>

GunManager::GunManager(){
   Gun gun;

   std::ifstream fin("gun.dat", std::ofstream::binary);
   while (fin.read((char *)&gun, sizeof(Gun))){   // lê do arquivo 
      gunVector.push_back(gun);

      int id = gun.getId();

      sf::SoundBuffer buffer;
      if(id == 1){
         buffer.loadFromFile("audio/machete.wav");
      }else if(id == 2){
         buffer.loadFromFile("audio/colt_shot.wav");
      }else if(id == 3){
         buffer.loadFromFile("audio/luger_shot.wav");
      }else if(id == 4){
         buffer.loadFromFile("audio/mouser_shot.wav");
      }else if(id == 5){
         buffer.loadFromFile("audio/luger_shot.wav");
      }else if(id == 6){
         buffer.loadFromFile("audio/hotchkiss_shot.wav");
      }
      gunAudio.push_back(buffer);
   }
   fin.close();
}

Gun GunManager::getGun(int id){
   for(int i=0;i<gunVector.size();i++){
      if(gunVector[i].getId() == id){
         return gunVector[i];
      }
   }
}

sf::Sound GunManager::getAudio(int id){
   sf::Sound sound;
   sound.setBuffer(gunAudio[id-1]);
   sound.setVolume(20);
   sound.setLoop(false);

   return sound;
}