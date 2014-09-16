#ifndef CHARENEMMY_HPP
#define CHARENEMMY_HPP

#include "Character.hpp"
#include "CollisionManager.hpp"
#include <string>
#include <stdlib.h> /* rand */
#include <time.h> /* time */
#include <MapLoader.h>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class CharEnemmy : public Character {
private:
	//Direction code is the number of direction to the movimentation. Left=1, Up=2, Right=3 and Down=4
	int codDirection;
	int oldCodDirection;
	int alcanceVisao; 
	int pVc[4];
	float velocity;
	CollisionObject * visionX;
	CollisionObject * visionY;

	sf::Vector2f      collisionMarginVision;

	bool              follow_flag;
	sf::Vector2f      follow_dest;
	int               follow_side;

	bool hited;
	int  color;

    sf::Clock clock;
    sf::Time time;
    float elapsed;

    sf::Clock gunClock;
    float gunElapsed;

	void readSpawnAreas(tmx::MapLoader * mapLoader);

	void pushTrigger(sf::Vector2f dest);
public:
	CharEnemmy(float screen_x, float screen_y, CollisionManager * cManager, tmx::MapLoader * mapLoader);

	void update();

	bool testVision();

	bool getFollow();

	sf::Sprite getSprite();

	void follow(sf::Vector2f dest);
};

#endif