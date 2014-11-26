#ifndef DROPMANAGER_HPP
#define DROPMANAGER_HPP

#include <vector>
#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\Text.hpp>
#include <SFML\Graphics\Font.hpp>
#include <SFML\System\Clock.hpp>

#include "Display.hpp"
#include "DropStamina.hpp"
#include "DropHealth.hpp"
#include "DropXp.hpp"
#include "DropBullets.hpp"
#include "DropColt.hpp"
#include "DropLuger.hpp"
#include "DropMauser.hpp"
#include "DropWinchester.hpp"
#include "CollisionManager.hpp"
#include "Random.hpp"

class DropManager{
private:
	Display              *   display;
	CollisionManager     *   collisionManager;
	std::vector<DropItem *>  vetor;
	sf::Vector2f             area;

	sf::Font                 verdana;
	sf::Text                 message;
	bool                     showMessage;

	bool                     getGun;

	sf::Clock                clock;
	float                    elapsed;
public:
	DropManager(Display * display, float areaX, float areaY, CollisionManager * collisionManager);

	void include(DropItem);
	void update();
	void draw();
	void sortItem(float, float);
	void sortItem(sf::Vector2f);
	void dropGun(int, float, float);
	void getGunOn();
};

#endif