#ifndef AURA_H
#define AURA_H

#include "WorldObject.h"
#include "ParticleSystem\ShapeEmitter.h"

class Aura : public WorldObject
{
	private:
		float rotspd;
		int damage = 5;

		RectangleEmitter * emit1;
		RectangleEmitter * emit2;
		RectangleEmitter * emit3;
	public:
		Aura(float x, float y);
		void collide(WorldObject * object);
		void init(Spielfeld * spiel);
		void tick();
		float getRotspeed();
		void setRotspeed(float rs);
};

#endif