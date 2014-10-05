#include "GunManager.hpp"

GunManager::GunManager(){
	Gun gun;

	std::ifstream fin("gun.dat", std::ofstream::binary);
	while (fin.read((char *)&gun, sizeof(Gun))){   // lê do arquivo 
  		gunVector.push_back(gun);
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