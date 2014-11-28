#include "GunManager.hpp"
#include <iostream>

GunManager::GunManager(){
   Gun gun;

   std::ifstream fin("gun.dat", std::ofstream::binary);
   while (fin.read((char *)&gun, sizeof(Gun))){   // lê do arquivo 
      gunVector.push_back(gun);

      int id = gun.getId();
      sf::Music * music = new sf::Music();

      if(id == 1){
         music->openFromFile("audio/machete.wav");
      }else if(id == 2){
         music->openFromFile("audio/colt_shot.wav");
      }else if(id == 3){
         music->openFromFile("audio/luger_shot.wav");
      }else if(id == 4){
         music->openFromFile("audio/mouser_shot.wav");
      }else if(id == 5){
         music->openFromFile("audio/luger_shot.wav");
      }else if(id == 6){
         music->openFromFile("audio/hotchkiss_shot.wav");
      }
      music->setVolume(20);
      music->setLoop(false);

      gunAudio.push_back(music);
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

sf::Music * GunManager::getAudio(int id){
   return gunAudio[id-1];
}