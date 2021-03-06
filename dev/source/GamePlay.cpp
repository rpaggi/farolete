#include "GamePlay.hpp"
#include "GameOver.hpp"
#include "Cutscene2.hpp"
#include "Cutscene3.hpp"
#include "GamePlayPost.hpp"
#include <iostream>

GamePlay::GamePlay(){
}

void GamePlay::start(){
   std::cout<<"Teste"<<std::endl;
   float screen_x = display->getSize().x;
   float screen_y = display->getSize().y;

   view = display->getView();

   display->setShowMousePointer(true);

   loadingTex.loadFromFile(LoaderImages().getImage());
   loadingSpr.setTexture(loadingTex);
   display->draw(loadingSpr);
   this->render();

   musicBg.openFromFile("audio/bg.ogg");
   musicBg.setLoop(true);
   musicBg.setVolume(25);

   menuInGame = new MenuInGame(display);

   bufferLoadWave.loadFromFile("audio/load_wave.wav");
   soundLoadWave.setBuffer(bufferLoadWave);
   soundLoadWave.setVolume(20);

   savingTex.loadFromFile("images/saving.png");
   savingSpr.setTexture(savingTex);

   home =   new GameKey(sf::Keyboard::Home);
   end =   new GameKey(sf::Keyboard::End);
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

   if(saveGame.hp > 0)
      farolete = new CharMain(screen_x, screen_y, collisionManager, display, saveGame.hp, saveGame.stamina, saveGame.xp, saveGame.bullets, saveGame.gunId);
   else
      farolete = new CharMain(screen_x, screen_y, collisionManager, display);

   dropManager = new DropManager(display, mapSize.x, mapSize.y, collisionManager);

   waveManager = new WaveManager(fase, screen_x, screen_y, collisionManager, mapLoader, display);
   if(saveGame.wave > 0){
      inimigos = waveManager->getWaveEnemmyList(saveGame.wave);
   }else{
      inimigos = waveManager->getWaveEnemmyList(1);
   }

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
   saving = false;

   pause = false;

   std::cout<<"WaveAtual: "<<waveManager->getWaveAtual()<<std::endl;
}

void GamePlay::draw(){
   display->clear(sf::Color(0,0,0,255));
   display->draw(mapLoader);

   dropManager->draw();

   for(unsigned i=0; i<inimigos.size();i++){
      inimigos[i]->draw();
   }

   farolete->draw();

   if(cont > 0){
      if(cont<=3){
         txtCont.setColor(sf::Color::Red);
      }else{
         txtCont.setColor(sf::Color(100, 100, 100));         
      }
      display->draw(txtCont);
   }

   hud->draw();

   if(pause) menuInGame->draw();

   if(saving) display->draw(savingSpr);;
}

void GamePlay::render(){
   display->display();
}

void GamePlay::logic(){
   if(pause){
      int ret = menuInGame->update(farolete->getXp(), farolete->getHp(), farolete->getBulletQtd(), farolete->getStamina());
      if(ret == 1){
         display->setShowMousePointer(true);
         musicBg.setVolume(25);
         pause = false;  
         clock.restart();       
      }else if(ret == 2){
         goScene = new GamePlayPost(display, 1);
         musicBg.stop();
         sceneManager->setCurrentScene(goScene);
      }

      if (keyboard.triggered(*esc)){
         display->setShowMousePointer(true);
         musicBg.setVolume(25);
         pause = false;
         clock.restart();
      }
   }else{
      time = clock.getElapsedTime();
      elapsed = time.asSeconds();

      screenMovement.x = 0.f;
      screenMovement.y = 0.f;

      sf::Vector2f iMovement;

      float vel = 2.2f;
      // if (keyboard.triggered(*end)){

      // }

      if (keyboard.triggered(*esc)){
         display->setShowMousePointer(false);
         musicBg.setVolume(15);
         pause = true;
      }

      // if (keyboard.triggered(*home)){
      //    farolete->switchGodMode();
      // }
      
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
            counter = elapsed;
         }else{
            if(elapsed-counter > 1.0){
               musicBg.stop();
               goScene = new GamePlayPost(display, 2);
               sceneManager->setCurrentScene(goScene);
            }
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

      savingSpr.setPosition((view.getCenter().x + display->getSize().x/2)-50, (view.getCenter().y + display->getSize().y/2)-94);

      if(inimigos.size() <= 0 /*|| keyboard.triggered(*end)*/){
         if(loadWave == 0){
            loadWave = elapsed;
         }

         cont = 10 - (elapsed - loadWave);

         std::ostringstream ss;

         ss<<"Tempo para proxima wave: ";
         if(cont<10){
            ss <<"0"<< cont;
         }else{
            ss << cont;
         }

         txtCont.setString(ss.str());

         if(elapsed - loadWave > 8){
            saving = true;
         }

         if(elapsed - loadWave >= 10 /*|| keyboard.triggered(*end)*/){
            //waveManager->setWaveAtual(waveManager->getWaveAtual() + 1);
            loadWave = 0;
            cont = 0;
            saving = false;
            bool continua = true;

            if(fase == 1 && waveManager->getWaveAtual() >= 5){
               musicBg.stop();
               saveGame.stage = 2;
               saveGame.wave  = 1;
               goScene = new GamePlayPost(display, 3);
               continua = false;
            }else if(fase == 2 && waveManager->getWaveAtual() >= 5){
               musicBg.stop();
               saveGame.stage = 1;
               saveGame.wave  = 1;
               goScene = new GamePlayPost(display, 4);
               continua = false;
            }else{
               inimigos = waveManager->getWaveEnemmyList(waveManager->getWaveAtual() + 1);
               saveGame.stage = fase;
               saveGame.wave  = waveManager->getWaveAtual();
               for(unsigned i=0;i<inimigos.size();i++){
                  inimigos[i]->activeCollision();
                  inimigos[i]->setDropManager(dropManager);
               }
               soundLoadWave.play();
            }
            
            saveGame.gunId = farolete->getGunId(1);
            saveGame.hp    = farolete->getHp();
            saveGame.stamina = farolete->getStamina();
            saveGame.xp = farolete->getXp();
            saveGame.bullets = farolete->getBulletQtd();
            saveGame.saveGame();

            if(!continua){
               sceneManager->setCurrentScene(goScene);
            }


         }
      }

      txtCont.setPosition((view.getCenter().x)-260, (view.getCenter().y - display->getSize().y/2) + 30);
   }
}

void GamePlay::finish(){
   delete home;
   delete end;
   delete esc;
   delete up;
   delete down;
   delete left;
   delete right;
   delete a_key;
   delete s_key;
   delete d_key;
   delete w_key;
   delete c_key;
   delete spacebar;
   delete snapshot_key;
   delete mb_left;
   delete mb_right;
   delete farolete;
   delete dropManager;
   delete waveManager;
   delete hud;
   delete collisionManager;
   delete menuInGame;
   delete this;
}