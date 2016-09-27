#ifndef AURA_H
#define AURA_H

#include "WorldObject.h"

class Aura : public WorldObject
{
	private:
		float rotspd;

		int damage = 5;


	public:
		Aura(float x, float y);

		void collide(WorldObject * object);
		void init(Spielfeld * spiel);
		void tick();
};

#endif