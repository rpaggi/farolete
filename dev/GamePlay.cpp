#include "GamePlay.hpp"

//Remove this shit mother fucker!
#include <iostream>
#include <cmath>

#define PI 3.14159265

GamePlay::GamePlay(Display * d){
	display = d;
	freeMouse = 0;
	timeShot = 0.3;
}

void GamePlay::start(){
	esc = new GameKey(sf::Keyboard::Escape);
	up = new GameKey(sf::Keyboard::Up);
	down = new GameKey(sf::Keyboard::Down);
	left = new GameKey(sf::Keyboard::Left);
	right = new GameKey(sf::Keyboard::Right);
	mapLoader = new tmx::MapLoader("maps/");
	mapLoader->Load("desert.tmx");

	perText.begin();

	for(int i=0;i<8;i++){
		perText.push_back(sf::Texture());
	}

	

	perText[0].loadFromFile("person/r.png");
	perText[1].loadFromFile("person/dor.png");
	perText[2].loadFromFile("person/do.png");
	perText[3].loadFromFile("person/dol.png");
	perText[4].loadFromFile("person/l.png");
	perText[5].loadFromFile("person/upl.png");
	perText[6].loadFromFile("person/up.png");
	perText[7].loadFromFile("person/upr.png");

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

	perSprite[0].setOrigin(perSprite[0].getTextureRect().width/2, perSprite[0].getTextureRect().height/2);
	perSprite[1].setOrigin(perSprite[1].getTextureRect().width/2, perSprite[1].getTextureRect().height/2);
	perSprite[2].setOrigin(perSprite[2].getTextureRect().width/2, perSprite[2].getTextureRect().height/2);
	perSprite[3].setOrigin(perSprite[3].getTextureRect().width/2, perSprite[3].getTextureRect().height/2);
	perSprite[4].setOrigin(perSprite[4].getTextureRect().width/2, perSprite[4].getTextureRect().height/2);
	perSprite[5].setOrigin(perSprite[5].getTextureRect().width/2, perSprite[5].getTextureRect().height/2);
	perSprite[6].setOrigin(perSprite[6].getTextureRect().width/2, perSprite[6].getTextureRect().height/2);
	perSprite[7].setOrigin(perSprite[7].getTextureRect().width/2, perSprite[7].getTextureRect().height/2);

}

void GamePlay::draw(){
	display->clear(sf::Color(255,255,255,255));

	display->draw(mapLoader);
	//mapLoader.draw(display->getWindow());

	for(unsigned i=0;i<vShot.size();i++){
		display->draw(vShot[i]->getSprite());
	}

	display->draw(perSprite[pos]);

}

void GamePlay::render(){
	display->display();
}

void GamePlay::logic(){
	time = clock.getElapsedTime();
	elapsed = time.asSeconds();

	sf::Vector2i mPos = display->getMousePosition();

	sf::View view = display->getView();

	screenMovement.x = 0.f;
	screenMovement.y = 0.f;

	if (keyboard.triggered(*esc))
        sceneManager->exit();
    if (keyboard.pressed(*up))
        screenMovement.y = -1.f;
    if (keyboard.pressed(*down))
        screenMovement.y = 1.f;
    if (keyboard.pressed(*left))
        screenMovement.x = -1.f;
    if (keyboard.pressed(*right))
        screenMovement.x = 1.f;
    
    float dt = time.asSeconds();
    screenMovement = Helpers::Vectors::Normalize(screenMovement) * 10.f;// * dt;
	view.move(screenMovement);
	display->setView(view);

	perCm.x = view.getCenter().x;
	perCm.y = view.getCenter().y;

	mPos.x = (view.getCenter().x - view.getSize().x/2) + mPos.x;
	mPos.y = (view.getCenter().y - view.getSize().y/2) + mPos.y;

	float angB = angBetween(perCm.x, perCm.y, mPos.x, mPos.y);


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

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && freeMouse < 1)
	{
		freeMouse++;
		clock.restart();
		vShot.push_back(new Shot(perCm.x, perCm.y, mPos.x, mPos.y));
	}

    
    for(unsigned i = 0;i<vShot.size();i++){
    	if(!vShot[i]->moveShot()){
    		delete vShot[i];
			vShot.erase(vShot.begin() + i);
		}
    }

    if(freeMouse > 0 && elapsed > timeShot){
    	clock.restart();
    	freeMouse--;
    }

    

    perSprite[pos].setPosition(view.getCenter());
}

void GamePlay::finish(){

}

float GamePlay::angBetween(float cmX, float cmY, float pX, float pY){
	float disX = pX-cmX;
	float disY = pY-cmY;

	float distance = sqrt(pow(disX, 2.0) + pow(disY,2.0));

	float s = disY/distance;
	float c = disX/distance;
	float ang = (atan2(s, c) * 180 / PI);
	if (ang < 0){
		ang += 360;
	}
	return ang;
}
