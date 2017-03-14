#ifndef DRONE_H
#define DRONE_H

#include "Gegner.h"
#include "LaserBox.h"

class Drone : public Gegner
{
private:

	sf::Vector2f destination;

	sf::Vector2f vel;

	int moveTime;

	int laserBoxTimer;
	int time;

	void spawnBox();
	void updateDestination();

public:
	Drone(float x, float y);
	void init(Spielfeld * spiel);
	void tick();
};

#endif