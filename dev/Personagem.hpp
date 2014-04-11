#ifndef PERSONAGEM_HPP
#define PERSONAGEM_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>

#include "AssetsManager.cpp"

namespace Textures
{
   enum ID
   {
       tex1,
       tex2,
       tex3,
       tex4,
       tex5,
       tex6,
       tex7,
       tex8,
   };
}

class Personagem{
	int position;
    sf::Vector2u massCenter;
    std::vector<sf::Sprite> sprites;
    AssetsManager<sf::Texture, Textures::ID> textures;

 public:
 	Personagem(float screen_h, float screen_w);

};

#endif