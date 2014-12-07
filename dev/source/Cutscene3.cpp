#include "Cutscene3.hpp"
#include "MainMenu.hpp"
#include <iostream>

Cutscene3::Cutscene3(Display * display){
	this->display = display;
}

void Cutscene3::start(){
    display->setShowMousePointer(false);

    sf::View view(sf::FloatRect(0,0,display->getSize().x, display->getSize().y));
    display->setView(view);

    space = new GameKey(sf::Keyboard::Space);

	texSeqA.loadFromFile("images/cutscenes/3/a.png");
	sprSeqA.setTexture(texSeqA);
	sprSeqA.setColor(sf::Color(255,255,255,0));

	musicBg.openFromFile("audio/cutscene.ogg");
	musicBg.setVolume(20);
	musicBg.setLoop(true);

	musicBg.play();

	momento = 0;

	clock.restart();
}

void Cutscene3::draw(){
	display->clear(sf::Color::Black);
	display->draw(sprSeqA);
}

void Cutscene3::render(){
	display->display();
}

void Cutscene3::logic(){
	elapsed = clock.getElapsedTime().asSeconds();
	int tempo1 = 15;

	switch(momento){
		case 0:
			if(elapsed > 1){
				momento = 1;
				clock.restart();
			}
		break;

		case 1:
			if(elapsed > 0.75){
				momento = 2;
				clock.restart();
			}else{
				trataSprite(1, &sprSeqA, 0.75);
			}
		break;

		case 2:
			if(keyboard.triggered(*space)){
				elapsed = tempo1+1;
			}
			if(elapsed > tempo1){
				momento = 3;
				clock.restart();
			}else{
				trataSprite(2, &sprSeqA, tempo1);
			}
		break;

		case 3:
			if(elapsed > 0.75){
				sprSeqA.setColor(sf::Color(255,255,255,0));
				goScene = new MainMenu(display);
				musicBg.stop();
				sceneManager->setCurrentScene(goScene);
			}else{
				trataSprite(3, &sprSeqA, 0.75);
			}
		break;
	}
}

void Cutscene3::finish(){
	delete this;
}

void Cutscene3::trataSprite(int function, sf::Sprite * sprite, float time){
	int value = 255/time;
	float alpha = 255;

	switch(function){
		// Fade-in
		case 1:
			alpha = value * elapsed;
			// alpha = 255-(value * elapsed);
		break;

		// Show only
		case 2:
			alpha = 255;
		break;

		// Fade-out
		case 3:
			alpha = 255-(value * elapsed);
			// alpha = value * elapsed;
		break;
	}

	sprite->setColor(sf::Color(255,255,255,alpha));
}
