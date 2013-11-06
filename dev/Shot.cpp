#include "Shot.hpp"

//Remove this shit mother fucker!
#include <iostream>

Shot::Shot(float pX, float pY, float dX, float dY){
	position.x = pX;
	position.y = pY;

	destination.x = dX;
	destination.y = dY;

	//Calculate the increment
	float aX, aY, iX, iY;

	aX = dX-pX;
	aY = dY-pY;

	if(aX<0){
		aX *= -1;
	}
	if(aY<0){
		aY *= -1;
	}

	if(aX>aY){
		iX = aX/aY;
		iY = aY/aY;
	}else{
		if(aX<aY){
			iX = aX/aX;
			iY = aY/aX;
		}else{
			iX = aX/aX;
			iY = aY/aY;
		}
	}

	if(dX<pX){
		iX *= -1;
	}
	if(dY<pY){
		iY *= -1;
	}

	increment.x = iX;
	increment.y = iY;

	texture.loadFromFile("shot/texture.png");
	sprite.setTexture(texture);

}

Shot::~Shot(){
}

void Shot::setPosition(float x, float y){
	position.x = x;
	position.y = y;
}

void Shot::setDestination(float x, float y){
	destination.x = x;
	destination.y = y;
}

bool Shot::moveShot(){
	time = clock.getElapsedTime();
	elapsed = time.asSeconds();
	int controlReturn = 0;

	if(elapsed > 0.005){
		clock.restart();
		if(increment.x < 0){
			if((position.x + increment.x) <= destination.x){
				controlReturn ++;
			}else{
				position.x += increment.x;
			}
		}else{
			if((position.x + increment.x) >= destination.x){
				controlReturn ++;
			}else{
				position.x += increment.x;
			}
		}

		if(increment.x < 0){
			if((position.y + increment.y) <= destination.y){
				controlReturn ++;
			}else{
				position.y += increment.y;
			}
		}else{
			if((position.y + increment.y) >= destination.y){
				controlReturn ++;
			}else{
				position.y += increment.y;
			}
		}

		sprite.setPosition(position.x,position.y);

	}

	if (controlReturn >= 2){
		return false;
	}else{
		return true;
	}
}

sf::Sprite Shot::getSprite(){
	return sprite;
}