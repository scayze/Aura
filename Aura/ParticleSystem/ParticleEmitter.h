#ifndef PARTICLEEMITTER_H
#define PARTICLEEMITTER_H

#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics\RenderWindow.hpp>
#include "../RessourceManager/Resources.h"

struct Particle
{
	sf::Vector2f position;
	sf::Vector2f velocity;
	float size;
	int time;
};

class ParticleEmitter
{
	protected:
		sf::Vector2f position;
		//Storage of Particles
		std::vector<Particle> particles;
		//Density of Particles beeing emitted. values between 0 and 1, 1 meaning one particle every tick;
		float density;
		//The amount of Particles that get burstet when constructed
		int count;
		//Lifetime of the Particles
		int lifetime;
		//Lifetime difference possible between particles
		int lifetimeOffset;
		//Maximum velocity of each particle
		float maxVelocity;
		//float minVeloctiy;
		//Scale of Particle
		float scale;
		//float minVeloctiy
		//Scale difference pssible between particles
		float scaleOffset;

	public:
		ParticleEmitter(sf::Vector2f pos);

		virtual void tick();
		void init();
		virtual void render(sf::RenderWindow * rW) = 0;

		void addParticle();

		void setPosition(sf::Vector2f pos);
		void setCount(int n);
		void setDensity(int n);
		void setLifetime(int n);
		void setLifetimeOffset(int n);
		void setMaxVelocity(float v);

		bool flag_destroy = false;
};

#endif