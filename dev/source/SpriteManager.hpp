#ifndef SPRITEMANAGER_HPP
#define SPRITEMANAGER_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Clock.hpp>
#include <string>

#include "Display.hpp"

class SpriteManager{
private:
	Display      *display;
	sf::Clock     clock;
	float         lastTime;
	sf::Texture   texture;
	sf::Sprite    sprite;
	sf::Vector2f  fSize;
	bool          hide;
	bool          hited;
	int           animationFrame;
	float         frameRate;
	int           color;
	int           alpha;
	bool          animateM;

public:
	SpriteManager(Display * d, std::string file);

	void draw();

	/* To the update method, the side definition is:
	 * 1 = behind / up
	 * 2 = front   / down
	 * 3 = left side
	 * 4 = right side
	 */
	void update(int gunId, int side);

	void animate();
	void animateMachete();

	void setPosition(sf::Vector2f position);

	void setHide(bool hide);

	void hit();

	void setFrameRate(float fr);
};

#endif
