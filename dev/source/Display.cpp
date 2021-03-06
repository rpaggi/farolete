#include "Display.hpp"
#include <iostream>

Display::Display() {
   window.create(sf::VideoMode(1280, 720), "Farolete", sf::Style::Fullscreen);
   //Use window mode to dev the game (:
   // window.create(sf::VideoMode(1024, 600), "xingu"); 
   window.setVerticalSyncEnabled(true);
   window.setMouseCursorVisible(false);
   window.clear(sf::Color::Black);
   window.display();
   m_pointer_texture.loadFromFile("images/cursor.png");
   m_pointer_sprite.setTexture(m_pointer_texture);
   m_pointer_sprite.setPosition(-30, -30);

   window.setFramerateLimit(60);

   showMousePointer = false;
}

void Display::handleEvents() {
   sf::Event event;
   while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed)
         window.close();
   }
}

bool Display::isOpen() {
   return window.isOpen(); 
}

sf::Vector2u Display::getSize() {
   return window.getSize();
}

sf::Vector2f Display::getSize2f() {
   return sf::Vector2f(window.getSize().x, window.getSize().y);
}

const sf::View & Display::getView() {
   return window.getView();
}

void Display::setView(sf::View view) {
   window.setView(view);
}

void Display::display() {
   if(showMousePointer) window.draw(m_pointer_sprite);

   window.display();
}

void Display::draw(sf::Sprite sprite) {
   window.draw(sprite);
}

void Display::draw(sf::Text text) {
   window.draw(text);
}

void Display::draw(tmx::MapLoader* map) {
   window.draw(*map);
}

void Display::draw(sf::RectangleShape rectangleShape) {
   window.draw(rectangleShape);
}

void Display::clear(sf::Color color) {
   window.clear(color);
}

bool Display::pollEvent(sf::Event e) {
   return window.pollEvent(e);
}

sf::Vector2i Display::getMousePosition(){
   sf::Vector2i mp = sf::Mouse::getPosition();
   
   sf::View view = window.getView();
   mp.x += ((view.getCenter().x*2) - view.getSize().x)/2;
   mp.y += ((view.getCenter().y*2) - view.getSize().y)/2;
   m_pointer_sprite.setPosition(mp.x, mp.y);
   
   return sf::Mouse::getPosition();
   // return sf::Mouse::getPosition(window);
}

void Display::printScreen(){
   time_t now = time(0);
   char* dt = ctime(&now);

   std::stringstream filename;
   sf::Image image = window.capture();
   filename << "screenshots/screenshot_" << dt[4]<<dt[5]<<dt[6]<<dt[8]<<dt[9]<<dt[11]<<dt[12]<<dt[14]<<dt[15]<<dt[17]<<dt[18] << ".png";
   image.saveToFile( filename.str() );
}

void Display::setShowMousePointer(bool value){
   showMousePointer = value;
   if(!value)
      m_pointer_sprite.setPosition(-50, -50);
}