#include  "Stage1.hpp"
#include <iostream>

Stage1::Stage1(Display * d){
   display = d;

   mapLoader = new tmx::MapLoader("maps/map1/");
   mapLoader->Load("map1.tmx");

   float screen_x = display->getSize().x;
   float screen_y = display->getSize().y;

   fase = 1;
   wave = 1;
}

void Stage1::logic(){
   GamePlay::logic();
}