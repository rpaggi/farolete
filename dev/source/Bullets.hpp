#ifndef BULLETS_HPP
#define BULLETS_HPP

//#include <math.h>
#include <cmath>
#include <vector>
#include <string>
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

#include "CollisionManager.hpp"

class Bullets{
	std::vector<sf::Vector2f>     position;
	std::vector<sf::Vector2f>     destination;
	std::vector<sf::Vector2f>     increment;
	std::vector<bool>             hidden;
	std::vector<CollisionObject*> collisionObject;
	CollisionManager *            collisionManager;
	sf::Vector2f                  massCenter;
	float                         velocity;
	sf::Texture                   texture;
	sf::Sprite                    sprite;
	sf::RenderTexture             renderTexture;
	sf::View                      view;
    sf::Clock                     clock;
	sf::Time                      time;
	float                         elapsed;

public:
	Bullets(sf::Vector2f mass_center, sf::Vector2f screen_size);

	void setCollisionManager(CollisionManager * cManager);

	void includeBullet(sf::Vector2f dest);

	void moveBullets();

	sf::Sprite getSprite();

	void setView(sf::View view);

};

#endif