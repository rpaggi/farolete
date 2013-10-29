#include "GamePlay.hpp"
#include <iostream>

#define PI 3.141593

GamePlay::GamePlay(Display * d){
	display = d;
}

void GamePlay::start(){
	esc = new GameKey(sf::Keyboard::Escape);

	perText.begin();
	for(int i=0;i<8;i++){
		perText.push_back(sf::Texture());
	}

	perText[0].loadFromFile("person/up.png");
	perText[1].loadFromFile("person/upr.png");
	perText[2].loadFromFile("person/r.png");
	perText[3].loadFromFile("person/dor.png");
	perText[4].loadFromFile("person/do.png");
	perText[5].loadFromFile("person/dol.png");
	perText[6].loadFromFile("person/l.png");
	perText[7].loadFromFile("person/upl.png");

	perSprite.begin();
	for(int i=0;i<8;i++){
		perSprite.push_back(sf::Sprite());
	}

	perSprite[0].setTexture(perText[0]);
	perSprite[1].setTexture(perText[1]);
	perSprite[2].setTexture(perText[2]);
	perSprite[3].setTexture(perText[3]);
	perSprite[4].setTexture(perText[4]);
	perSprite[5].setTexture(perText[5]);
	perSprite[6].setTexture(perText[6]);
	perSprite[7].setTexture(perText[7]);
	

	float sX = display->getSize().x/2;
	float sY = display->getSize().y/2;

	perCm.x = sX;
	perCm.y = sY;

	perSprite[0].setPosition(sX-(perText[0].getSize().x/2),sY-(perText[0].getSize().y/2));
	perSprite[1].setPosition(sX-(perText[1].getSize().x/2),sY-(perText[1].getSize().y/2));
	perSprite[2].setPosition(sX-(perText[2].getSize().x/2),sY-(perText[2].getSize().y/2));
	perSprite[3].setPosition(sX-(perText[3].getSize().x/2),sY-(perText[3].getSize().y/2));
	perSprite[4].setPosition(sX-(perText[4].getSize().x/2),sY-(perText[4].getSize().y/2));
	perSprite[5].setPosition(sX-(perText[5].getSize().x/2),sY-(perText[5].getSize().y/2));
	perSprite[6].setPosition(sX-(perText[6].getSize().x/2),sY-(perText[6].getSize().y/2));
	perSprite[7].setPosition(sX-(perText[7].getSize().x/2),sY-(perText[7].getSize().y/2));

}

void GamePlay::draw(){
	display->clear(sf::Color(255,255,255,255));
	display->draw(perSprite[pos]);

}

void GamePlay::render(){
	display->display();
}

void GamePlay::logic(){
	sf::Vector2i mPos = display->getMousePosition();
	float angB = angBetween(perCm.x, perCm.y, mPos.x, (display->getSize().y-mPos.y));

	if((angB>0 && angB<22.5) || (angB>=337 && angB<=360)){
		pos = 0;
	}else if(angB>=22.5 && angB<67.5){
		pos = 1;
	}else if(angB>=67.5 && angB<112.5){
		pos = 2;
	}else if(angB>=112.5 && angB<157.5){
		pos = 3;
	}else if(angB>=157.5 && angB<202.5){
		pos = 4;
	}else if(angB>=202.5 && angB<247.5){
		pos = 5;
	}else if(angB>=247.5 && angB<292.5){
		pos = 6;
	}else if(angB>=292.5 && angB<337){
		pos = 7;
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		std::cout<<angB<<std::endl;
	}

	if (keyboard.triggered(*esc)){
        sceneManager->exit();
    }

}

void GamePlay::finish(){

}

float GamePlay::angBetween(float cmX, float cmY, float pX, float pY){
	float disX = pX-cmX;
	float disY = pY-cmY;

	float aTan2 = atan2(disX, disY);
	float ang = (aTan2) * 180/PI;

	if (ang < 0){
		ang += 360;
	}

	return ang;
}
