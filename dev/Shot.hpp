#ifndef SHOT_HPP
#define SHOT_HPP

#include <math.h>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class Shot{
	sf::Vector2f position;
	sf::Vector2f destination;
	sf::Vector2f increment;
	sf::Texture  texture;
	sf::Sprite   sprite;
    sf::Clock clock;
	sf::Time time;
	float elapsed;

public:
	Shot(float pX, float pY, float dX, float dY);

	~Shot();

	void setPosition(float x, float y);
	void setDestination(float x, float y);

	bool moveShot();

	sf::Sprite getSprite();

};

#endif