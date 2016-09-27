#ifndef PARTICLE_H
#define PARTICLE_H

#include "WorldObject.h"

class Particle : public WorldObject
{
	private:


	public:
		Particle(float x, float y);
		void init(Spielfeld * spiel);
		void tick();
};

#endif