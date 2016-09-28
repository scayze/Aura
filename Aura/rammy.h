#ifndef Rammy_H
#define Rammy_H

#include "Rammy.h"
#include "LaserBox.h"

class Rammy : public Gegner
{
private:

	int state;
	float speed = 6.f;
	sf::Vector2f destination;

	sf::Vector2f vel;

	int moveTime;

	int laserBoxTimer;
	int time;



public:
	Rammy(float x, float y);
	void init(Spielfeld * spiel);
	void tick();
};

#endif