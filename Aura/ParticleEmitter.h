#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include "WorldObject.h"
#include "Particle.h"

class ParticleEmitter : public WorldObject
{
	private:
		float density;
		std::vector<Particle> particles;
		float speed;

	public:
		ParticleEmitter(float x, float y);
		void init(Spielfeld * spiel);
		void tick();
};

#endif