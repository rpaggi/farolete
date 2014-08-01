#include "Character.hpp"
#include <iostream>

Character::Character(){
}

sf::Sprite Character::getSprite(){
	sf::Sprite spriteTemp;

	renderTexture.clear(sf::Color(255,255,255,0));
	renderTexture.draw(bullets->getSprite());
	renderTexture.draw(sprite);
	renderTexture.display();

	sf::View view = renderTexture.getView();
	spriteTemp.setTexture(renderTexture.getTexture());
	spriteTemp.setPosition(((view.getCenter().x*2) - view.getSize().x)/2,
		                   ((view.getCenter().y*2) - view.getSize().y)/2);

	return spriteTemp;
}

void Character::setView(sf::View view){
	renderTexture.setView(view);
	bullets->setView(view);
}

int Character::getHp(){
	return hp;
}
