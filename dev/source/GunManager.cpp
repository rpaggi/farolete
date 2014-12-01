#include "GunManager.hpp"
#include <iostream>

GunManager::GunManager(){
   Gun gun;

   std::ifstream fin("gun.dat", std::ofstream::binary);
   while (fin.read((char *)&gun, sizeof(Gun))){   // lê do arquivo 
      gunVector.push_back(gun);

      int id = gun.getId();

      std::string buffer;
      if(id == 1){
         buffer = "audio/machete.wav";
      }else if(id == 2){
         buffer = "audio/colt_shot.wav";
      }else if(id == 3){
         buffer = "audio/luger_shot.wav";
      }else if(id == 4){
         buffer = "audio/mouser_shot.wav";
      }else if(id == 5){
         buffer = "audio/winchester_shot.wav";
      }else if(id == 6){
         buffer = "audio/hotchkiss_shot.wav";
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

std::string GunManager::getAudio(int id){
   return gunAudio[id-1];
}