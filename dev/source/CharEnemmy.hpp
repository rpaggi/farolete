#ifndef CHARENEMMY_HPP
#define CHARENEMMY_HPP

#include "Character.hpp"
#include "CollisionManager.hpp"
#include <string>

class CharEnemmy : public Character {
private:
	//Direction code is the number of direction to the movimentation. Left=1, Up=2, Right=3 and Down=4
	int codDirection;
	int oldCodDirection;
	int alcanceVisao; 
	int pVc[4];
	CollisionObject cObj;
public:
	CharEnemmy();
};

#endif