#include "Drone.h"
#include "Spieler.h"
#include <iostream>

Drone::Drone(float x, float y) : Gegner(x, y)
{
	RessourceManager::loadTexture(texture, "Drone.png");

	maxHealthPoints = 20;
	moveTime = 0;
	speed = 3.f;
	time = 300;
	laserBoxTimer = time/0.6;

	destination.x = rand();
	destination.y = rand();
	destination = Math::vectorSetMagnitude(destination, 80);
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

	destination.x = rand() - RAND_MAX / 2;
	destination.y = rand() - RAND_MAX / 2;

	while (i < 10 && Math::vectorDistance(body->getPos() + destination, spielfeld->getPlayer()->getBody()->getPos()) < 80.f)
	{

		i++;
		destination.x = rand() - RAND_MAX / 2;
		destination.y = rand() - RAND_MAX / 2;
		std::cout << destination.x << std::endl;
		destination = Math::vectorSetMagnitude(destination, 150);

	}

	vel = Math::vectorSetMagnitude(destination, speed);
	moveTime = 150 / speed;
}