#include "Cutscene2.hpp"
#include "Stage2.hpp"

Cutscene2::Cutscene2(Display * display){
	this->display = display;
}

void Cutscene2::start(){
    display->setShowMousePointer(false);

    sf::View view(sf::FloatRect(0,0,display->getSize().x, display->getSize().y));
    display->setView(view);

    space = new GameKey(sf::Keyboard::Space);

	texSeqA.loadFromFile("images/cutscenes/2/a.png");
	sprSeqA.setTexture(texSeqA);
	sprSeqA.setColor(sf::Color(255,255,255,0));

	texSeqB.loadFromFile("images/cutscenes/2/b.png");
	sprSeqB.setTexture(texSeqB);
	sprSeqB.setColor(sf::Color(255,255,255,0));

	momento = 0;

	savegame.loadGame();

	clock.restart();
}

void Cutscene2::draw(){
	display->clear(sf::Color::Black);
	display->draw(sprSeqA);
	display->draw(sprSeqB);
}

void Cutscene2::render(){
	display->display();
}

void Cutscene2::logic(){
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
			if(elapsed > 1){
				momento = 2;
				clock.restart();
			}else{
				trataSprite(1, &sprSeqA, 1);
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
				momento = 4;
				clock.restart();
				sprSeqA.setColor(sf::Color(255,255,255,0));
			}else{
				trataSprite(3, &sprSeqA, 0.75);
				trataSprite(1, &sprSeqB, 0.75);
			}
		break;

		case 4:
			if(keyboard.triggered(*space)){
				elapsed = tempo1+1;
			}
			if(elapsed > tempo1){
				momento = 5;
				clock.restart();
			}else{
				trataSprite(2, &sprSeqB, tempo1);
			}
		break;

		case 5:
			if(elapsed > 0.75){
				goScene = new Stage2(display, savegame);
				sceneManager->setCurrentScene(goScene);
				sprSeqB.setColor(sf::Color(255,255,255,0));
			}else{
				trataSprite(3, &sprSeqB, 0.75);
			}
		break;
	}
}

void Cutscene2::finish(){
	delete this;
}

void Cutscene2::trataSprite(int function, sf::Sprite * sprite, float time){
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
