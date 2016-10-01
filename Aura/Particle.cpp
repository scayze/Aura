#include "Particle.h"

Particle::Particle(float x, float y) : WorldObject(x,y)
{
	flag_visible = false;
}

void Particle::init(Spielfeld * spiel)
{
	WorldObject::init(spiel);
}

void Particle::tick()
{
	WorldObject::tick();
}