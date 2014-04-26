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

	
	try
	{
		textures.load(Textures::personTex1, "person/r.png");
		textures.load(Textures::personTex2, "person/dor.png");
		textures.load(Textures::personTex3, "person/do.png");
		textures.load(Textures::personTex4, "person/dol.png");
		textures.load(Textures::personTex5, "person/l.png");
		textures.load(Textures::personTex6, "person/upl.png");
		textures.load(Textures::personTex7, "person/up.png");
		textures.load(Textures::personTex8, "person/upr.png");
	}
	catch (std::runtime_error& e)
	{
	}

	perSprite.begin();
	for(int i=0;i<8;i++){
		perSprite.push_back(sf::Sprite());
	}

	perSprite[0].setTexture(textures.get(Textures::personTex1));
	perSprite[1].setTexture(textures.get(Textures::personTex2));
	perSprite[2].setTexture(textures.get(Textures::personTex3));
	perSprite[3].setTexture(textures.get(Textures::personTex4));
	perSprite[4].setTexture(textures.get(Textures::personTex5));
	perSprite[5].setTexture(textures.get(Textures::personTex6));
	perSprite[6].setTexture(textures.get(Textures::personTex7));
	perSprite[7].setTexture(textures.get(Textures::personTex8));

	float sX = display->getSize().x/2;
	float sY = display->getSize().y/2;

	perCm.x = sX;
	perCm.y = sY;

	perSprite[0].setPosition(sX-(textures.get(Textures::personTex1).getSize().x/2),sY-(textures.get(Textures::personTex1).getSize().y/2));
	perSprite[1].setPosition(sX-(textures.get(Textures::personTex2).getSize().x/2),sY-(textures.get(Textures::personTex2).getSize().y/2));
	perSprite[2].setPosition(sX-(textures.get(Textures::personTex3).getSize().x/2),sY-(textures.get(Textures::personTex3).getSize().y/2));
	perSprite[3].setPosition(sX-(textures.get(Textures::personTex4).getSize().x/2),sY-(textures.get(Textures::personTex4).getSize().y/2));
	perSprite[4].setPosition(sX-(textures.get(Textures::personTex5).getSize().x/2),sY-(textures.get(Textures::personTex5).getSize().y/2));
	perSprite[5].setPosition(sX-(textures.get(Textures::personTex6).getSize().x/2),sY-(textures.get(Textures::personTex6).getSize().y/2));
	perSprite[6].setPosition(sX-(textures.get(Textures::personTex7).getSize().x/2),sY-(textures.get(Textures::personTex7).getSize().y/2));
	perSprite[7].setPosition(sX-(textures.get(Textures::personTex8).getSize().x/2),sY-(textures.get(Textures::personTex8).getSize().y/2));

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
