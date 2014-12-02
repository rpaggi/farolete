#include  "Stage2.hpp"
#include <iostream>

Stage2::Stage2(Display * d){
   display = d;

   mapLoader = new tmx::MapLoader("maps/map2/");
   mapLoader->Load("map2.tmx");

   float screen_x = display->getSize().x;
   float screen_y = display->getSize().y;

   fase = 2;
}

void Stage2::logic(){
   GamePlay::logic();
}