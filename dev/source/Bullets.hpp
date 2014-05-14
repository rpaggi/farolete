#ifndef BULLETS_HPP
#define BULLETS_HPP

//#include <math.h>
#include <cmath>
#include <vector>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class Bullets{
	std::vector<sf::Vector2f> position;
	std::vector<sf::Vector2f> destination;
	std::vector<sf::Vector2f> increment;
	sf::Vector2f              massCenter;
	float                     velocity;
	sf::Texture               texture;
	sf::Sprite                sprite;
	sf::RenderTexture         renderTexture;
    sf::Clock                 clock;
	sf::Time                  time;
	float                     elapsed;

public:
	Bullets(sf::Vector2f mass_center, sf::Vector2f screen_size);

	void includeBullet(sf::Vector2f dest);

	void moveBullets();

	sf::Sprite getSprite();

	void setView(sf::View view);

};

#endif