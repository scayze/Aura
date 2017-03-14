#ifndef LASERBOX_H
#define LASERBOX_H

#include "Gegner.h"
#include "Laser.h"

class LaserBox : public Gegner
{
private:

	int timeBetweenShots;
	int timer;

	int chargeTime;

	sf::Vector2f dir;

	float range;
	void fireLaser();
public:
	LaserBox(float x, float y);
	void init(Spielfeld * spiel);
	void tick();
};

#endif