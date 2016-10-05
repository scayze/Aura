#include "Aura.h"
#include "Figur.h"
#include <iostream>
Aura::Aura(float x, float y) : WorldObject(x,y)
{

	Resources::loadTexture(texture,"Sword.png");
    rotspd = 8;

	delete body;
	body = new EdgeBody();
	body->setCollisionType(t_aura);
	body->addCollisionWith(t_gegner);
	body->setPos(x, y);
	body->setMass(-1);

}

void Aura::init(Spielfeld * spiel)
{
	WorldObject::init(spiel);
    sprite.setOrigin(-32,sprite.getGlobalBounds().height/2);
	//static_cast<CircleBody*>(body)->setRadius(80);
	static_cast<EdgeBody*>(body)->setP2(sf::Vector2f(body->getPos().x + 80, body->getPos().y));
}

void Aura::tick()
{
	WorldObject::tick();
	sprite.setRotation(sprite.getRotation()+rotspd);
	EdgeBody * b = static_cast<EdgeBody*>(body);

	body->updateAABB();
	b->setP2(Math::vectorRotateAroundPoint(b->getP2(), sf::Vector2f(0,0), rotspd / 180.f * Math::PI()));
}

void Aura::collide(WorldObject * object)
{
	if (object->getBody()->getCollisionType() == t_gegner)
	{
		if (!static_cast<Figur*>(object)->isInvincible()) rotspd = -rotspd;
		static_cast<Figur*>(object)->dealDamage(damage);
	}
}

float Aura::getRotspeed()
{
	return rotspd;
}

void Aura::setRotspeed(float rs)
{
	rotspd = rs;
}