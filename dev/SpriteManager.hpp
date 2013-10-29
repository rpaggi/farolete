#ifndef SPRITEMANAGER_HPP
#define SPRITEMANAGER_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

#include "Display.hpp"

class SpriteManager{
private:
	Display * display;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2u fSize;
	int countFrames;
    int counter;
    int refreshRate;
public:
	SpriteManager();

	void start(Display * d, std::string file, int countF, int refreshRate);

	void draw();

	void change();

	void setPosition(float x, float y);

	sf::Sprite getSprite();
};

#endif
