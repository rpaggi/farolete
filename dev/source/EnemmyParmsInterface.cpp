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

int EnemmyParmsInterface::getIdGun(){
	return idGun;
}