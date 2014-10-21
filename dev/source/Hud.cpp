#include "Hud.hpp"
#include <iostream>

Hud::Hud(Display * d){
   display = d;

   //Load and set the texture of background into sprite
   bgTex.loadFromFile("images/hud/bg.png");
   bgSpr.setTexture(bgTex);

   hpTex.loadFromFile("images/hud/hp.png");
   hpSize = sf::Vector2f(210,34);
   hpSpr.setTexture(hpTex);
   hpSpr.setTextureRect(sf::IntRect(0, 0, hpSize.x, hpSize.y));

   stTex.loadFromFile("images/hud/stamina.png");
   stSize = sf::Vector2f(187, 30);
   stSpr.setTexture(stTex);
   stSpr.setTextureRect(sf::IntRect(0, 0, stSize.x, stSize.y));

   gTex.loadFromFile("images/hud/guns.png");
   gSize = sf::Vector2f(113,30);
   gSpr.setTexture(gTex);
   gSpr.setTextureRect(sf::IntRect(0, 0, gSize.x, gSize.y));

   bTex.loadFromFile("images/hud/bullets.png");
   bFont.loadFromFile("images/hud/verdanab.ttf");
   bSpr.setTexture(bTex);
   bSize = sf::Vector2f(50,29);
   bSpr.setTextureRect(sf::IntRect(0, 0, bSize.x, bSize.y));
   bText.setFont(bFont);
   bText.setString("20");
   bText.setCharacterSize(10);
   bText.setColor(sf::Color::Black);
   bDraw = false;
}

void Hud::draw(){
   sf::View view = display->getView();
   sf::Vector2f bgPos;

   //Go to the end of the screen and subtract the background size with a margin of 10 pixels.
   // bgPos.x = (view.getCenter().x + (display->getSize().x/2)) - bgTex.getSize().x-10;
   bgPos.x = (view.getCenter().x - (display->getSize().x/2)) + 10;
   bgPos.y = (view.getCenter().y + (display->getSize().y/2)) - bgTex.getSize().y-10;
   // bgPos.y = (view.getCenter().y - (display->getSize().y/2)) + 10;

   //Set the position of background
   bgSpr.setPosition(bgPos);

   //Set the position of hp bar
   hpSpr.setPosition(bgPos.x+171.5, bgPos.y+38);

   //Set the position of stamina bar
   stSpr.setPosition(bgPos.x+171.5, bgPos.y+81.5);

   //Set the position of guns icons
   gSpr.setPosition(bgPos.x+228, bgPos.y+116.5);

   //Set the position of bullets icons
   bSpr.setPosition(bgPos.x+170, bgPos.y+115);

   //Draw the sprites
   display->draw(bgSpr);
   display->draw(hpSpr);
   display->draw(stSpr);
   display->draw(gSpr);
   display->draw(bSpr);

   if(bDraw){
      //Set the position of text 
      bText.setPosition(bSpr.getPosition().x+17, bSpr.getPosition().y+12);
      display->draw(bText);
   }
}

void Hud::update(float hp, float st, int g, int b){
   //Update the hp bar
   if(hp>=90 && hp <=100){
      hpSpr.setTextureRect(sf::IntRect(0, 0, hpSize.x, hpSize.y));
   }else if(hp>=80 && hp<90){
      hpSpr.setTextureRect(sf::IntRect(0, (hpSize.y*1), hpSize.x, hpSize.y));
   }else if(hp>=70 && hp<80){
      hpSpr.setTextureRect(sf::IntRect(0, (hpSize.y*2), hpSize.x, hpSize.y));
   }else if(hp>=60 && hp<70){
      hpSpr.setTextureRect(sf::IntRect(0, (hpSize.y*3), hpSize.x, hpSize.y));
   }else if(hp>=50 && hp<60){
      hpSpr.setTextureRect(sf::IntRect(0, (hpSize.y*4), hpSize.x, hpSize.y));
   }else if(hp>=40 && hp<50){
      hpSpr.setTextureRect(sf::IntRect(0, (hpSize.y*5), hpSize.x, hpSize.y));
   }else if(hp>=30 && hp<40){
      hpSpr.setTextureRect(sf::IntRect(0, (hpSize.y*6), hpSize.x, hpSize.y));
   }else if(hp>=20 && hp<30){
      hpSpr.setTextureRect(sf::IntRect(0, (hpSize.y*7), hpSize.x, hpSize.y));
   }else if(hp>=10 && hp<20){
      hpSpr.setTextureRect(sf::IntRect(0, (hpSize.y*8), hpSize.x, hpSize.y));
   }else if(hp>0 && hp<10){
      hpSpr.setTextureRect(sf::IntRect(0, (hpSize.y*9), hpSize.x, hpSize.y));
   }else if(hp<=0){
      hpSpr.setTextureRect(sf::IntRect(0, (hpSize.y*10), hpSize.x, hpSize.y));
   }
   
   //Update the stamina bar
   if(st>=90 && st <=100){
      stSpr.setTextureRect(sf::IntRect(0, 0, stSize.x, stSize.y));
   }else if(st>=80 && st<90){
      stSpr.setTextureRect(sf::IntRect(0, (stSize.y*1), stSize.x, stSize.y));
   }else if(st>=70 && st<80){
      stSpr.setTextureRect(sf::IntRect(0, (stSize.y*2), stSize.x, stSize.y));
   }else if(st>=60 && st<70){
      stSpr.setTextureRect(sf::IntRect(0, (stSize.y*3), stSize.x, stSize.y));
   }else if(st>=50 && st<60){
      stSpr.setTextureRect(sf::IntRect(0, (stSize.y*4), stSize.x, stSize.y));
   }else if(st>=40 && st<50){
      stSpr.setTextureRect(sf::IntRect(0, (stSize.y*5), stSize.x, stSize.y));
   }else if(st>=30 && st<40){
      stSpr.setTextureRect(sf::IntRect(0, (stSize.y*6), stSize.x, stSize.y));
   }else if(st>=20 && st<30){
      stSpr.setTextureRect(sf::IntRect(0, (stSize.y*7), stSize.x, stSize.y));
   }else if(st>=10 && st<20){
      stSpr.setTextureRect(sf::IntRect(0, (stSize.y*8), stSize.x, stSize.y));
   }else if(st>0 && st<10){
      stSpr.setTextureRect(sf::IntRect(0, (stSize.y*9), stSize.x, stSize.y));
   }else if(st<=0){
      stSpr.setTextureRect(sf::IntRect(0, (stSize.y*10), stSize.x, stSize.y));
   }

   if(g == 1){
      gSpr.setTextureRect(sf::IntRect(0, gSize.y*2, gSize.x, gSize.y));
   }else if(g == 2 || g == 3){
      gSpr.setTextureRect(sf::IntRect(0, gSize.y*1, gSize.x, gSize.y));
   }else if(g == 4 || g == 5){
      gSpr.setTextureRect(sf::IntRect(0, gSize.y*3, gSize.x, gSize.y));
   }else{
      gSpr.setTextureRect(sf::IntRect(0, gSize.y*0, gSize.x, gSize.y));
   }

   bDraw = false;
   if(g<=1){
      bSpr.setTextureRect(sf::IntRect(0, bSize.y*0, bSize.x, bSize.y));
   }else{
      if(b<=0){
         bSpr.setTextureRect(sf::IntRect(0, bSize.y*1, bSize.x, bSize.y));
      }else{
         bDraw = true;
         std::ostringstream ss;
         if(b<10){
            ss <<"0"<< b;
         }else{
            ss << b;
         }
         bText.setString(ss.str());
         bSpr.setTextureRect(sf::IntRect(0, bSize.y*2, bSize.x, bSize.y));
      }
   }
}