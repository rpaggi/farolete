#ifndef LOADERIMAGES_HPP
#define LOADERIMAGES_HPP

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

#include "Random.hpp"

class LoaderImages{
private:

public:
	LoaderImages();

	sf::Sprite getImage();
};

#endif