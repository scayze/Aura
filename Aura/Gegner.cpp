#include "Gegner.h"
#include <iostream>
Gegner::Gegner(float x, float y) : Figur(x,y)
{
	body->setCollisionType(t_gegner);
	body->addCollisionWith(t_spieler | t_gegner);

    speed = 8;
	body->setMass(10);

	healthPoints = 500;
}

void Gegner :: tick()
{
    Figur::tick();
}

void Gegner::init(Spielfeld * feld)
{
	Figur::init(feld);
}
