#include "Bullets.hpp"

#define PI 3.14159265


Bullets::Bullets(sf::Vector2f mass_center, sf::Vector2f screen_size){
	massCenter = mass_center;
	velocity = 5;

	texture.loadFromFile("images/bullet/texture.png");
	renderTexture.create(screen_size.x, screen_size.y);
}

void Bullets::includeBullet(sf::Vector2f dest){
	//Calculate the increment
	float distance;
	sf::Vector2f aux;

	aux = dest-massCenter;
	distance = sqrt(pow(aux.x, 2.0) + pow(aux.y,2.0));

	increment.push_back(sf::Vector2f());
	increment[increment.size()-1].x = velocity * (aux.x/distance);
	increment[increment.size()-1].y = velocity * (aux.y/distance);

	position.push_back(sf::Vector2f());
	position[position.size()-1] = massCenter;

	destination.push_back(sf::Vector2f());
	destination[destination.size()-1] = dest;
}

void Bullets::moveBullets() {
	time = clock.getElapsedTime();
	elapsed = time.asSeconds();
	bool controlReturn = true;

	if (elapsed > 0.005) {
		for(unsigned i=0;i<position.size();i++){
			if (increment[i].x < 0 && increment[i].y < 0) {
				if ((position[i].x + increment[i].x) <= destination[i].x && (position[i].y + increment[i].y) <= destination[i].y)
					controlReturn = false;
			} else if (increment[i].x > 0 && increment[i].y < 0) {
				if ((position[i].x + increment[i].x) >= destination[i].x && (position[i].y + increment[i].y) <= destination[i].y)
					controlReturn = false;
			} else if (increment[i].x < 0 && increment[i].y > 0) {
				if ((position[i].x + increment[i].x) <= destination[i].x && (position[i].y + increment[i].y) >= destination[i].y)
					controlReturn = false;
			} else if (increment[i].x > 0 && increment[i].y > 0) {
				if ((position[i].x + increment[i].x) >= destination[i].x && (position[i].y + increment[i].y) >= destination[i].y)
					controlReturn = false;
			}

			if (controlReturn == true) {
				position[i].x += increment[i].x;
				position[i].y += increment[i].y;
			} else {
				position.erase(position.begin() + i);
				increment.erase(increment.begin() + i);
				destination.erase(destination.begin() + i);
			}

			controlReturn = true;
		}
		clock.restart();
	}
}

sf::Sprite Bullets::getSprite(){
	sf::Sprite sprTemp;
	sf::View view = renderTexture.getView();
	sf::Vector2f viewMovement;
	
	sprTemp.setTexture(texture);
	renderTexture.clear(sf::Color(255,255,255,0));

	viewMovement.x = ((view.getCenter().x*2) - view.getSize().x)/2;
	viewMovement.y = ((view.getCenter().y*2) - view.getSize().y)/2;

	for(unsigned i=0;i<position.size();i++){
		sprTemp.setPosition(position[i]+viewMovement);
		renderTexture.draw(sprTemp);
		renderTexture.display();
	}

	sprite.setTexture(renderTexture.getTexture());
	sprite.setPosition(viewMovement);
	
	return sprite;
}

void Bullets::setView(sf::View view){
	renderTexture.setView(view);
}