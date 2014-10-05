#ifndef GUNMANAGER_HPP
#define GUNMANAGER_HPP

#include <vector>
#include <fstream> 
#include "Gun.hpp"

class GunManager {	
private:
	std::vector<Gun> gunVector;
public:
	GunManager();

	Gun getGun(int id);
};

#endif