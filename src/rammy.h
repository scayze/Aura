#ifndef Rammy_H
#define Rammy_H

#include "Gegner.h"

class Rammy : public Gegner
{
private:
	int state = 0;

	int cooldown;
	int cooldownTime;

	sf::Vector2f ramDir;

	float normalSpeed;
	float ramSpeed;
	float ramActivationRange;

public:
	Rammy(float x, float y);
	void init(Spielfeld * s);
	void tick();

};



#endif
