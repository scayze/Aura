#include "ParticleEmitter.h"
#include <iostream>

ParticleEmitter::ParticleEmitter(float x, float y) : WorldObject(x,y)
{
	density = 0.15f;
	flag_visible = false;
	RessourceManager::loadTexture(texture,"fire.png");
}

void ParticleEmitter::init(Spielfeld * spiel)
{
	WorldObject::init(spiel);
}

void ParticleEmitter :: tick()
{
	if((float)rand() / (float)RAND_MAX < density)
	{
		std::cout << "fag";
		Particle * part = spielfeld->createObject<Particle>(body->getPos().x,body->getPos().y);
		part->getSprite().setTexture(texture);
		part->getSprite().setOrigin(part->getSprite().getGlobalBounds().width/2,part->getSprite().getGlobalBounds().height/2);
	}
}