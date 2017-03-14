#include "rammy.h"
#include "Spieler.h"
#include <iostream>

Rammy::Rammy(float x, float y) : Gegner(x, y)
{
	Resources::loadTexture(texture, "Rammy.png");

	maxHealthPoints = 15;

	cooldownTime = 90;
	cooldown = 0;

	speed = 3.f;
	normalSpeed = 4.5f;
	ramSpeed = 12.f;
	ramActivationRange = 300.f;

	static_cast<CircleBody*>(body)->setRadius(9);
}

void Rammy::tick()
{
	Gegner::tick();
	//body->setVel(vel);
	sprite.setRotation(Math::vectorGetRotation(body->getVel()) * 180 / Math::PI());
	cooldown--;
	if (state == 0)
	{
		body->setVel(Math::vectorSetMagnitude(spielfeld->getPlayer()->getBody()->getPos() - body->getPos(), speed));



		if (Math::vectorDistance(spielfeld->getPlayer()->getBody()->getPos(), body->getPos()) < ramActivationRange && cooldown <= 0)
		{
			sf::Vector2f dir = spielfeld->getPlayer()->getBody()->getPos() - body->getPos();

			std::vector<RayCastObject> resultVector = spielfeld->getPhysicsSystem()->rayCast(body->getPos(), dir, (bodyType)-1, t_terrain);


			float sqDistPlayer = Math::vectorSquaredDistance(body->getPos(), spielfeld->getPlayer()->getBody()->getPos());

			bool pathToPlayerBlocked = false;
			for (unsigned int i = 0; i < resultVector.size(); i++)
			{
				if (resultVector[i].body != body)
				{
					if (resultVector[i].point *resultVector[i].point < sqDistPlayer)
					{
						pathToPlayerBlocked = true;
					}
				}
			}

			if (!pathToPlayerBlocked)
			{
				state = 1;
				cooldown = cooldownTime;
			}
		}
	}
	else if (state == 1)
	{
		ramDir = Math::vectorNormalize(body->getVel());
		if (cooldown < cooldownTime - 10) state = 2;
	}
	else if (state == 2)
	{
		body->setVel(ramDir * ramSpeed);
		if (cooldown < cooldownTime - 50) state = 0;
	}

}

void Rammy::init(Spielfeld * s)
{
	Gegner::init(s);
	sprite.setScale(1.5, 1.5);
}

