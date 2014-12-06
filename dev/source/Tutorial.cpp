#include "Tutorial.hpp"
#include "Cutscene1.hpp"

Tutorial::Tutorial(Display * display){
	this->display = display;
}

void Tutorial::start(){
    display->setShowMousePointer(false);

    sf::View view(sf::FloatRect(0,0,display->getSize().x, display->getSize().y));
    display->setView(view);

    space = new GameKey(sf::Keyboard::Space);

	texImg1.loadFromFile("images/tutorial/img1.png");
	sprImg1.setTexture(texImg1);
	sprImg1.setColor(sf::Color(255,255,255,0));

	texImg2.loadFromFile("images/tutorial/img2.png");
	sprImg2.setTexture(texImg2);
	sprImg2.setColor(sf::Color(255,255,255,0));

	momento = 0;

	clock.restart();
}

void Tutorial::draw(){
	display->clear(sf::Color::Black);
	display->draw(sprImg1);
	display->draw(sprImg2);
}

void Tutorial::render(){
	display->display();
}

void Tutorial::logic(){
	elapsed = clock.getElapsedTime().asSeconds();
	switch(momento){
		case 0:
			if(elapsed > 1){
				momento = 1;
				clock.restart();
			}
		break;

		case 1:
			if(elapsed > 0.3){
				momento = 2;
				clock.restart();
			}else{
				trataSprite(1, &sprImg1, 0.3);
			}
		break;

		case 2:
			if(keyboard.triggered(*space)){
				momento = 3;
				clock.restart();
			}

			trataSprite(2, &sprImg1, 0);
		break;

		case 3:
			if(elapsed > 0.3){
				momento = 4;
				clock.restart();
				sprImg1.setColor(sf::Color(255,255,255,0));
			}else{
				trataSprite(3, &sprImg1, 0.3);
				trataSprite(1, &sprImg2, 0.3);
			}
		break;

		case 4:
			if(keyboard.triggered(*space)){
				momento = 5;
				clock.restart();
			}

			trataSprite(2, &sprImg2, 0);
		break;

		case 5:
			if(elapsed > 0.3){
				sprImg2.setColor(sf::Color(255,255,255,0));
				goScene = new Cutscene1(display);
				sceneManager->setCurrentScene(goScene);
			}else{
				trataSprite(3, &sprImg2, 0.3);
			}
		break;
	}
}

void Tutorial::finish(){
	delete this;
}

void Tutorial::trataSprite(int function, sf::Sprite * sprite, float time){
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
