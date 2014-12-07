#include "Cutscene1.hpp"
#include "Stage1.hpp"

Cutscene1::Cutscene1(Display * display){
	this->display = display;
}

void Cutscene1::start(){
    display->setShowMousePointer(false);

    sf::View view(sf::FloatRect(0,0,display->getSize().x, display->getSize().y));
    display->setView(view);

    space = new GameKey(sf::Keyboard::Space);

	texSeqA.loadFromFile("images/cutscenes/1/a.png");
	sprSeqA.setTexture(texSeqA);
	sprSeqA.setColor(sf::Color(255,255,255,0));

	texSeqB.loadFromFile("images/cutscenes/1/b.png");
	sprSeqB.setTexture(texSeqB);
	sprSeqB.setColor(sf::Color(255,255,255,0));

	texSeqC.loadFromFile("images/cutscenes/1/c.png");
	sprSeqC.setTexture(texSeqC);
	sprSeqC.setColor(sf::Color(255,255,255,0));

	texSeqD.loadFromFile("images/cutscenes/1/d.png");;
	sprSeqD.setTexture(texSeqD);
	sprSeqD.setColor(sf::Color(255,255,255,0));

	bufferBg.loadFromFile("audio/cutscene.ogg");
	soundBg.setBuffer(bufferBg);
	soundBg.setVolume(20);
	soundBg.setLoop(true);

	soundBg.play();

	momento = 0;

	clock.restart();
}

void Cutscene1::draw(){
	display->clear(sf::Color::Black);
	display->draw(sprSeqA);
	display->draw(sprSeqB);
	display->draw(sprSeqC);
	display->draw(sprSeqD);
}

void Cutscene1::render(){
	display->display();
}

void Cutscene1::logic(){
	elapsed = clock.getElapsedTime().asSeconds();
	int tempo1 = 6;

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
			if(elapsed > 0.50){
				momento = 4;
				clock.restart();
				sprSeqA.setColor(sf::Color(255,255,255,0));
			}else{
				trataSprite(3, &sprSeqA, 0.50);
				trataSprite(1, &sprSeqB, 0.50);
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
				momento = 6;
				clock.restart();
				sprSeqB.setColor(sf::Color(255,255,255,0));
			}else{
				trataSprite(3, &sprSeqB, 0.75);
				trataSprite(1, &sprSeqC, 0.75);
			}
		break;

		case 6:
			if(keyboard.triggered(*space)){
				elapsed = tempo1+1;
			}
			if(elapsed > tempo1){
				momento = 7;
				clock.restart();
			}else{
				trataSprite(2, &sprSeqC, tempo1);
			}
		break;

		case 7:
			if(elapsed > 0.50){
				momento = 8;
				clock.restart();
				sprSeqC.setColor(sf::Color(255,255,255,0));
			}else{
				trataSprite(3, &sprSeqC, 0.50);
				trataSprite(1, &sprSeqD, 0.50);
			}
		break;

		case 8:
			if(keyboard.triggered(*space)){
				elapsed = tempo1+1;
			}
			if(elapsed > tempo1){
				momento = 9;
				clock.restart();
			}else{
				trataSprite(2, &sprSeqD, tempo1);
			}
		break;

		case 9:
			if(elapsed > 0.75){
				sprSeqD.setColor(sf::Color(255,255,255,0));
				goScene = new Stage1(display);
				sceneManager->setCurrentScene(goScene);
			}else{
				trataSprite(3, &sprSeqD, 0.75);
			}
		break;

	}
}

void Cutscene1::finish(){
	soundBg.stop();
	delete this;
}

void Cutscene1::trataSprite(int function, sf::Sprite * sprite, float time){
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
