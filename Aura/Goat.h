#ifndef Goat_H
#define Goat_H

#include "Gegner.h"

class Goat : public Gegner
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
	Goat(float x, float y);
	void init(Spielfeld * s);
	void tick();

};



#endif
