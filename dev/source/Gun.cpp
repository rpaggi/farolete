#include "Gun.hpp"

Gun::Gun(){ 

}

int Gun::getId(){
	return id;
}
std::string Gun::getName(){
	return name;
}

int Gun::getRange(){
	return range;
}

int Gun::getCadence(){
	return cadence;
}

int Gun::getDamage(){
	return damage;
}

int Gun::getWeight(){
	return weight;
}