#include "Drone.h"
#include "Spieler.h"
#include <iostream>

Drone::Drone(float x, float y) : Gegner(x, y)
{
	Resources::loadTexture(texture, "Drone.png");

	maxHealthPoints = 20;
	moveTime = 0;
	speed = 3.f;
	time = 300;
	laserBoxTimer = (float)time/0.6f;

	destination.x = (float)rand();
	destination.y = (float)rand();
	destination = Math::vectorSetMagnitude(destination, 80);
	static_cast<CircleBody*>(body)->setRadius(9);
}

void Drone::tick()
{
	Gegner::tick();
	laserBoxTimer--;
	body->setVel(vel);

	if (moveTime == 0) updateDestination();
	moveTime--;

	if (laserBoxTimer == 0)
	{
		spawnBox();
		laserBoxTimer = time;
	}
}

void Drone::init(Spielfeld * s)
{
	Gegner::init(s);
	updateDestination();
	//sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
	sprite.setScale(1.5, 1.5);
}

void Drone::spawnBox()
{
	spielfeld->createObject<LaserBox>(body->getPos().x, body->getPos().y);
}

void Drone::updateDestination()
{
	int i = 0;

	destination.x = (float)rand() - (float)RAND_MAX / 2;
	destination.y = (float)rand() - (float)RAND_MAX / 2;

	while (i < 10 && Math::vectorDistance(body->getPos() + destination, spielfeld->getPlayer()->getBody()->getPos()) < 80.f)
	{

		i++;
		destination.x = (float)rand() - (float)RAND_MAX / 2;
		destination.y = (float)rand() - (float)RAND_MAX / 2;
		std::cout << destination.x << std::endl;
		destination = Math::vectorSetMagnitude(destination, 150);

	}

	vel = Math::vectorSetMagnitude(destination, speed);
	moveTime = 150.f / speed;
}