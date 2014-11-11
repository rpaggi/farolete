#ifndef THREADENEMMY_HPP
#define THREADENEMMY_HPP

#include "Display.hpp"
#include "CharEnemmy.hpp"
#include "CharMain.hpp"
#include <vector>
#include <SFML/System/Vector2.hpp>
#include <SFML/System/Thread.hpp>
#include <SFML/Window/Context.hpp>

class ThreadEnemmy{

public:
	Display * display;
	std::vector<CharEnemmy *> enemmies;
	CharMain * charmain;
	sf::View view;

	ThreadEnemmy(std::vector<CharEnemmy *> enemmies, CharMain * charmain, Display * dis);

	void draw();
	void update();

};


#endif