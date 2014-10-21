#ifndef HUD_HPP
#define HUD_HPP

#include "Display.hpp"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
#include <sstream>

class Hud{
private:
   Display *         display;

   sf::Texture       bgTex;
   sf::Sprite        bgSpr;

   sf::Texture       hpTex;
   sf::Sprite        hpSpr;
   sf::Vector2f      hpSize;

   sf::Texture       stTex;
   sf::Sprite        stSpr;
   sf::Vector2f      stSize;

   sf::Texture       gTex;
   sf::Sprite        gSpr;
   sf::Vector2f      gSize;

   sf::Texture       bTex;
   sf::Sprite        bSpr;
   sf::Font          bFont;
   sf::Text          bText;
   bool              bDraw;
   sf::Vector2f      bSize;

public:
   Hud(Display * d);

   void draw();

   void update(float hp, float st, int g, int b);
};

#endif