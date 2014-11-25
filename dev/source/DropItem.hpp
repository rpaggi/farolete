#ifndef DROPITEM_HPP
#define DROPITEM_HPP

#include "CollisionObject.hpp"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>

class DropItem{       
protected:
	int                 id;
	sf::Texture         texture;
	sf::Sprite          sprite;
	char                type;
	CollisionObject *   collisionObject;

public:
	DropItem();

	void              start();
	sf::Sprite        getSprite();
	CollisionObject * getCollisionObject();
	int               getId();
	void              setId(int id);
	char              getType();

	int               getGunId();
};

#endif