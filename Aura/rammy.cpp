#include "Rammy.h"
#include "Spieler.h"
#include <iostream>

Rammy::Rammy(float x, float y) : Gegner(x, y)
{
	RessourceManager::loadTexture(texture, "Drone.png");

	maxHealthPoints = 20;

	static_cast<CircleBody*>(body)->setRadius(9);
}

void Rammy::tick()
{
	Gegner::tick();
	body->setVel(vel);

}

void Rammy::init(Spielfeld * s)
{
	Gegner::init(s);
	sprite.setScale(1.5, 1.5);
}

