#include "EnemmyParmsInterface.hpp"

EnemmyParmsInterface::EnemmyParmsInterface(){

}

int EnemmyParmsInterface::getId(){
	return id;
}

std::string EnemmyParmsInterface::getName(){
	return name;
}

float EnemmyParmsInterface::getVelocity(){
	return velocity;
}

float EnemmyParmsInterface::getHp(){
	return hp;
}

int EnemmyParmsInterface::getIdGun(){
	return idGun;
}