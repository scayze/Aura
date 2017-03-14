#ifndef LASER_H
#define LASER_H

#include "WorldObject.h"

class Laser : public WorldObject
{
private:
	int ticksUntilDamage;

public:
	Laser(float x, float y);
	void init(Spielfeld * spiel);
	void tick();

	void collide(WorldObject * object);
};

#endif