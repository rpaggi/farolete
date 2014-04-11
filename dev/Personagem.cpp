#include "Personagem.hpp"

Personagem::Personagem(float screen_h, float screen_w){

  //Load textures to AssetsManager
  try
  {
    textures.load(Textures::tex1, "person/r.png");
    textures.load(Textures::tex2, "person/dor.png");
    textures.load(Textures::tex3, "person/do.png");
    textures.load(Textures::tex4, "person/dol.png");
    textures.load(Textures::tex5, "person/l.png");
    textures.load(Textures::tex6, "person/upl.png");
    textures.load(Textures::tex7, "person/up.png");
    textures.load(Textures::tex8, "person/upr.png");
  }
  catch (std::runtime_error& e)
  {
  }

  //Go to start of sprites vector
  sprites.begin();
  //Initialize the sprites vector
  for(int i=0;i<8;i++){
    sprites.push_back(sf::Sprite());
  }

  //Set textures of the sprites using the textures of assets manager
  sprites[0].setTexture(textures.get(Textures::tex1));
  sprites[1].setTexture(textures.get(Textures::tex2));
  sprites[2].setTexture(textures.get(Textures::tex3));
  sprites[3].setTexture(textures.get(Textures::tex4));
  sprites[4].setTexture(textures.get(Textures::tex5));
  sprites[5].setTexture(textures.get(Textures::tex6));
  sprites[6].setTexture(textures.get(Textures::tex7));
  sprites[7].setTexture(textures.get(Textures::tex8));

  //Define the mass center of person using the screen size pushed from parameter
  massCenter.x = screen_w/2;
  massCenter.y = screen_h/2;

  //Define sprites positions
  sprites[0].setPosition(massCenter.x-(textures.get(Textures::tex1).getSize().x/2),massCenter.y-(textures.get(Textures::tex1).getSize().y/2));
  sprites[1].setPosition(massCenter.x-(textures.get(Textures::tex2).getSize().x/2),massCenter.y-(textures.get(Textures::tex2).getSize().y/2));
  sprites[2].setPosition(massCenter.x-(textures.get(Textures::tex3).getSize().x/2),massCenter.y-(textures.get(Textures::tex3).getSize().y/2));
  sprites[3].setPosition(massCenter.x-(textures.get(Textures::tex4).getSize().x/2),massCenter.y-(textures.get(Textures::tex4).getSize().y/2));
  sprites[4].setPosition(massCenter.x-(textures.get(Textures::tex5).getSize().x/2),massCenter.y-(textures.get(Textures::tex5).getSize().y/2));
  sprites[5].setPosition(massCenter.x-(textures.get(Textures::tex6).getSize().x/2),massCenter.y-(textures.get(Textures::tex6).getSize().y/2));
  sprites[6].setPosition(massCenter.x-(textures.get(Textures::tex7).getSize().x/2),massCenter.y-(textures.get(Textures::tex7).getSize().y/2));
  sprites[7].setPosition(massCenter.x-(textures.get(Textures::tex8).getSize().x/2),massCenter.y-(textures.get(Textures::tex8).getSize().y/2));

  //Define origin of sprite
  sprites[0].setOrigin(sprites[0].getTextureRect().width/2, sprites[0].getTextureRect().height/2);
  sprites[1].setOrigin(sprites[1].getTextureRect().width/2, sprites[1].getTextureRect().height/2);
  sprites[2].setOrigin(sprites[2].getTextureRect().width/2, sprites[2].getTextureRect().height/2);
  sprites[3].setOrigin(sprites[3].getTextureRect().width/2, sprites[3].getTextureRect().height/2);
  sprites[4].setOrigin(sprites[4].getTextureRect().width/2, sprites[4].getTextureRect().height/2);
  sprites[5].setOrigin(sprites[5].getTextureRect().width/2, sprites[5].getTextureRect().height/2);
  sprites[6].setOrigin(sprites[6].getTextureRect().width/2, sprites[6].getTextureRect().height/2);
  sprites[7].setOrigin(sprites[7].getTextureRect().width/2, sprites[7].getTextureRect().height/2);

}