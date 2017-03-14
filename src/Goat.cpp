#include "Goat.h"
#include "Spieler.h"
#include <iostream>

Goat::Goat(float x, float y) : Gegner(x, y)
{
	Resources::loadTexture(texture, "Rammy.png");

	maxHealthPoints = 15;

	cooldownTime = 90;
	cooldown = 0;

	speed = 2.0f;
	normalSpeed = 4.f;
	ramSpeed = 6.5f;
	ramActivationRange = 400.f;

	dizzleTime = 0;

	static_cast<CircleBody*>(body)->setRadius(9);


}

void Goat::tick()
{

	Gegner::tick();

	sprite.setRotation(Math::vectorGetRotation(body->getVel()) * 180 / Math::PI());
	cooldown--;
	dizzleTime--;

	if (state == 0)
	{

		body->setVel(Math::vectorSetMagnitude(sf::Vector2f(spielfeld->getPlayer()->getBody()->getPos() - body->getPos()), normalSpeed));

		if (Math::vectorDistance(spielfeld->getPlayer()->getBody()->getPos(), body->getPos()) < ramActivationRange && cooldown <= 0)
		{
			state = 1;
			cooldown = cooldownTime;

		}
	}
	else if (state == 1)
	{
		speed += 0.015f;
		body->setVel(Math::vectorRotateToVector(body->getVel(), sf::Vector2f(spielfeld->getPlayer()->getBody()->getPos() - body->getPos()), 0.035f ));
		body->setVel(Math::vectorSetMagnitude(body->getVel(), speed));
		if (speed >= ramSpeed)
		{
			speed = 2.0f;
			state = 3;
			dizzleTime = 25;
		}

	}
	else if (state == 2)
	{
		body->setVel(ramDir * ramSpeed);
		if (cooldown < cooldownTime - 40) state = 0;
	}
	else if (state == 3)
	{
		body->setVel(Math::vectorSetMagnitude(body->getVel(),0.1));
		if (dizzleTime<=0) state = 0;
	}

}

void Goat::collide(WorldObject * wo)
{
	if (wo->getBody()->isCollisionType(t_terrain))
	{
		//state = 3;
		dizzleTime = 25;
	}
}

void Goat::init(Spielfeld * s)
{

	Gegner::init(s);
	sprite.setScale(1.5, 1.5);
	body->setVel(Math::vectorSetMagnitude(spielfeld->getPlayer()->getBody()->getPos() - body->getPos(), speed));
}

