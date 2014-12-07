#ifndef MENUINGAME_HPP
#define MENUINGAME_HPP 

#include <string>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <string>
#include <sstream>

#include "Display.hpp"
#include "Input.hpp"

class MenuInGame{
private:
	Display * display;

	KeyboardInput keyboard;

	GameKey* w_key;
	GameKey* s_key;
	GameKey* enter;

	sf::Texture texBg;
	sf::Sprite  sprBg;

	sf::Texture texBtnRetornar;
	sf::Sprite  sprBtnRetornar;

	sf::Texture texBtnMenuPrincipal;
	sf::Sprite  sprBtnMenuPrincipal;

	sf::Font    verdana;

	sf::Text    txtXp;
	sf::Text    txtHp;
	sf::Text    txtBullets;
	sf::Text    txtStamina;

	int         selected;
public:
	MenuInGame(Display * d);

	void draw();

	int update(int xp, int hp, int bullets, int stamina);

};

#endif