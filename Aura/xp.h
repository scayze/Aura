#ifndef XP_H
#define XP_H

#include <SFML\Graphics.hpp>
#include "Worldobject.h"

class Xp : public WorldObject
{
private:
	float speeeeeed;
	int amount;
public:
	Xp(float x, float y);
	void setAmount(int n);
	void tick();
	void collide(WorldObject *obj);
};

#endif