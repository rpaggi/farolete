#include "Character.hpp"
#include <iostream>

Character::Character(){
   hp = 100;
}

void Character::draw(){
   // sf::Sprite spriteTemp;

   // renderTexture.clear(sf::Color(255,255,255,0));
   // renderTexture.draw(bullets->getSprite());
   // renderTexture.draw(sprite);
   // renderTexture.display();

   // display->draw(bullets->getSprite());
   bullets->draw();
   display->draw(sprite);

   // sf::View view = renderTexture.getView();
   // spriteTemp.setTexture(renderTexture.getTexture());
   // spriteTemp.setPosition(((view.getCenter().x*2) - view.getSize().x)/2,
   //                       ((view.getCenter().y*2) - view.getSize().y)/2);
}

void Character::setView(sf::View view){
   bullets->setView(view);
}

int Character::getHp(){
   return hp;
}
