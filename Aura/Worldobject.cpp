#include "Worldobject.h"
#include <iostream>


WorldObject::WorldObject(float x, float y)
{
	texture.loadFromFile("bla.png");

	type = t_noCollide;

	body = new CircleBody();

	body->setPos(x,y);
	speed = 6.f;

	flag_destroy = false;
	flag_visible = true;
}

void WorldObject::init(Spielfeld * spiel)
{
	spielfeld = spiel;
	sprite.setTexture(texture);
	sprite.setOrigin(sprite.getLocalBounds().width/2,sprite.getLocalBounds().height/2);
	
	body->setOwner(this);

}

void WorldObject::tick()
{
	if(!body->isStatic) body->tick();
	//sprite.setPosition(body->getPos());
}

void WorldObject::render(sf::RenderWindow * rW)
{
	rW->draw(sprite);
}

sf::Sprite& WorldObject::getSprite()
{
	return sprite;
}

Body * WorldObject::getBody()
{
	return body;
}

int WorldObject::getType()
{
	return type;
}

WorldObject::~WorldObject()
{
	body->flagDestroy = true;
}

void WorldObject::collide(WorldObject * obj)
{

}