#include "GamePlay.hpp"
#include <iostream>

GamePlay::GamePlay(){
}

void GamePlay::start(){
   float screen_x = display->getSize().x;
   float screen_y = display->getSize().y;

   view = display->getView();

   loadingTex.loadFromFile(LoaderImages().getImage());
   loadingSpr.setTexture(loadingTex);
   display->draw(loadingSpr);
   this->render();

   musicBg.openFromFile("audio./bg.ogg");
   musicBg.setLoop(true);
   musicBg.setVolume(15);

   bufferLoadWave.loadFromFile("audio/load_wave.wav");
   soundLoadWave.setBuffer(bufferLoadWave);
   soundLoadWave.setVolume(20);

   esc =   new GameKey(sf::Keyboard::Escape);
   up =    new GameKey(sf::Keyboard::Up);
   down =  new GameKey(sf::Keyboard::Down);
   left =  new GameKey(sf::Keyboard::Left);
   right = new GameKey(sf::Keyboard::Right);
   a_key = new GameKey(sf::Keyboard::A);
   s_key = new GameKey(sf::Keyboard::S);
   d_key = new GameKey(sf::Keyboard::D);
   w_key = new GameKey(sf::Keyboard::W);
   c_key = new GameKey(sf::Keyboard::C);
   spacebar = new GameKey(sf::Keyboard::Space);
   snapshot_key = new GameKey(sf::Keyboard::F12);

   mb_left = new MouseButton(sf::Mouse::Left);
   mb_right = new MouseButton(sf::Mouse::Right);

   collisionManager = new CollisionManager();

   sf::Vector2u mapSize = mapLoader->GetMapSize();
   collisionManager->include(mapLoader);

   farolete = new CharMain(screen_x, screen_y, collisionManager, display);

   dropManager = new DropManager(display, mapSize.x, mapSize.y, collisionManager);
   dropManager->sortItem(750, 780);

   waveManager = new WaveManager(fase, screen_x, screen_y, collisionManager, mapLoader, display);
   inimigos = waveManager->getWaveEnemmyList(1);

   for(unsigned i=0;i<inimigos.size();i++){
      inimigos[i]->activeCollision();
      inimigos[i]->setDropManager(dropManager);
   }

   loadWave = 0;

   mapSize.x = (mapSize.x/2)-(view.getSize().x/2);
   mapSize.y = (mapSize.y/2)-(view.getSize().y/2);

   //Initial Position
   view.move(mapSize.x-250, mapSize.y+30);

   hud = new Hud(display);

   cont = 0;
   verdana.loadFromFile("font/verdanab.ttf");
   txtCont.setFont(verdana);
   txtCont.setString("00");
   txtCont.setCharacterSize(32);

   faroleteKill = false;

   musicBg.play();
}

void GamePlay::draw(){
   display->clear(sf::Color(0,0,0,255));
   display->draw(mapLoader);

   dropManager->draw();
   
   farolete->draw();

   for(unsigned i=0; i<inimigos.size();i++){
      inimigos[i]->draw();
   }

   if(cont > 0){
      if(cont<=3){
         txtCont.setColor(sf::Color::Red);
      }else{
         txtCont.setColor(sf::Color(100, 100, 100));         
      }
      display->draw(txtCont);
   }

   hud->draw();
}

void GamePlay::render(){
   display->display();
}

void GamePlay::logic(){
   time = clock.getElapsedTime();
   elapsed = time.asSeconds();

   screenMovement.x = 0.f;
   screenMovement.y = 0.f;

   sf::Vector2f iMovement;

   float vel = 2.2f;
   if (keyboard.triggered(*esc)){
      sceneManager->exit();
   }
   
   if (keyboard.pressed(*w_key)){
      screenMovement.y = -vel;
   }else if (keyboard.pressed(*s_key)){
      screenMovement.y = vel;
   }else if (keyboard.pressed(*a_key)){
      screenMovement.x = -vel;
   }else if (keyboard.pressed(*d_key)){
      screenMovement.x = vel;
   }

   if (keyboard.triggered(*c_key)){
      dropManager->getGunOn();
   }

   if (keyboard.triggered(*snapshot_key)){
      display->printScreen();
   }

   if(keyboard.triggered(*spacebar)){
      farolete->switchGun();
   }

   //screenMovement = Helpers::Vectors::Normalize(screenMovement);

   if(!farolete->testCollisionMovement(screenMovement)){
      screenMovement.x = 0.f;
      screenMovement.y = 0.f;      
      screenMovement = Helpers::Vectors::Normalize(screenMovement);
   }

   mouse_position = display->getMousePosition();

   if(farolete->getHp() > 0){
      if(screenMovement.x != 0 || screenMovement.y != 0){
         farolete->animate();
      }

      view.move(screenMovement);
      display->setView(view);
      farolete->move(view.getCenter());
      farolete->setView(view);

      sf::Vector2f cast;
      cast.x = mouse_position.x;
      cast.y = mouse_position.y;

      if(farolete->getTriggerType() == 1){
         if (mouse.triggered(*mb_left)){
            farolete->pushTrigger(cast);   
         }else if(mouse.triggered(*mb_right)){
            farolete->fastTrigger(cast);
         }
      }else{
         if (mouse.pressed(*mb_left)){
            farolete->pushTrigger(cast);   
         }else if(mouse.pressed(*mb_right)){
            farolete->fastTrigger(cast);  
         }
      }
   }else{
      farolete->setHidden(true);
      if(!faroleteKill){
         farolete->kill();
         faroleteKill = true;
      }
   }

   farolete->update(mouse_position.x, mouse_position.y);
   hud->update(farolete->getHp(), farolete->getStamina(), farolete->getGunId(), farolete->getBulletQtd(), inimigos.size());
   dropManager->update();

   for(unsigned i=0; i<inimigos.size();i++){
      inimigos[i]->update();
      if((inimigos[i]->testVision() && !farolete->getHidden())
      ||  inimigos[i]->getFollow()  && !farolete->getHidden()){
         inimigos[i]->follow(view.getCenter());
      }else{
         inimigos[i]->follow(sf::Vector2f(-1,-1));
      }

      if(inimigos[i]->getHp() <= 0){
         farolete->addXp(inimigos[i]->getXp());
         inimigos[i]->kill();
         inimigos.erase(inimigos.begin() + i);
      }
   }

   if(inimigos.size() <= 0){
      if(loadWave == 0){
         loadWave = elapsed;
      }

      cont = 10 - (elapsed - loadWave);

      std::ostringstream ss;

      if(cont<10){
         ss <<"0"<< cont;
      }else{
         ss << cont;
      }

      txtCont.setString(ss.str());

      if(elapsed - loadWave >= 10){
         //waveManager->setWaveAtual(waveManager->getWaveAtual() + 1);
         inimigos = waveManager->getWaveEnemmyList(waveManager->getWaveAtual() + 1);
         loadWave = 0;
         cont = 0;
         for(unsigned i=0;i<inimigos.size();i++){
            inimigos[i]->activeCollision();
            inimigos[i]->setDropManager(dropManager);
         }
         soundLoadWave.play();
      }
   }

   txtCont.setPosition((view.getCenter().x)-10, (view.getCenter().y - display->getSize().y/2) + 30);
}

void GamePlay::finish(){
}