#include "ParticleEmitter.h"
#include <iostream>

ParticleEmitter::ParticleEmitter(sf::Vector2f pos) : position(pos)
{
	density = 1.f;

	lifetime = 280;
	lifetimeOffset = 20;

	count = 10000;

	//minVeloctiy = 1.f;
	maxVelocity = 1.f;

	scale = 2.f;
	scaleOffset = 1.f;
}


void ParticleEmitter :: tick()
{
	if((float)rand() / (float)RAND_MAX < density)
	{
		addParticle();
	}

	for (unsigned int i = 0; i < particles.size(); i++)
	{
		particles[i].position += particles[i].velocity;
		particles[i].time--;
		if (particles[i].time == 0)
		{
			particles.erase(particles.begin() + i);
		}
	}

	if (count > 0 && particles.empty()) flag_destroy = true;

}

void ParticleEmitter::init()
{
	for (int i = 0; i < count; i++)
	{
		addParticle();
	}
}

void ParticleEmitter::addParticle()
{
	Particle * part = new Particle;

	part->position = position;
	part->size = scale + (float)rand() / (float)RAND_MAX * scaleOffset * 2 - scaleOffset;
	part->velocity = sf::Vector2f((float)rand() / (float)RAND_MAX * maxVelocity * 2.f - maxVelocity, (float)rand() / (float)RAND_MAX * maxVelocity * 2.f - maxVelocity);
	part->time = lifetime + rand() % lifetimeOffset * 2 - lifetimeOffset;
	particles.push_back(*part);
}

void ParticleEmitter::setPosition(sf::Vector2f pos)
{
	position = pos;
}
void ParticleEmitter::setCount(int n)
{
	count = n;
}

void ParticleEmitter::setDensity(int n)
{
	density = n;
}

void ParticleEmitter::setLifetime(int n)
{
	lifetime = n;
}

void ParticleEmitter::setLifetimeOffset(int n)
{
	lifetimeOffset = n;
}

void ParticleEmitter::setMaxVelocity(float v)
{
	maxVelocity = v;
}