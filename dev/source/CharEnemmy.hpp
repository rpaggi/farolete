#ifndef CHARENEMMY_HPP
#define CHARENEMMY_HPP

#include "Character.hpp"
#include "CollisionManager.hpp"
#include <string>
#include <stdlib.h> /* rand */
#include <time.h> /* time */
#include <MapLoader.h>
#include <SFML/System/Time.hpp>

class CharEnemmy : public Character {
private:
	//Direction code is the number of direction to the movimentation. Left=1, Up=2, Right=3 and Down=4
	int codDirection;
	int oldCodDirection;
	int alcanceVisao; 
	int pVc[4];

	bool hited;
	int  color;

    sf::Clock clock;
    sf::Time time;
    float elapsed;

	void readSpawnAreas(tmx::MapLoader * mapLoader);
public:
	CharEnemmy(float screen_x, float screen_y, CollisionManager * cManager, tmx::MapLoader * mapLoader);

	void update();

	sf::Sprite getSprite();
};

#endif