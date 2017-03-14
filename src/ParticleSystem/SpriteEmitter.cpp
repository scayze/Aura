#include "SpriteEmitter.h"

SpriteEmitter::SpriteEmitter(sf::Vector2f pos) : ParticleEmitter(pos)
{
	Resources::loadTexture(pTexture, "fire.png");
	pSprite.setTexture(pTexture);
}

void SpriteEmitter::tick()
{
	ParticleEmitter::tick();
}

void SpriteEmitter::render(sf::RenderWindow * rW)
{
	for (unsigned int i = 0; i < particles.size(); i++)
	{
		//Apply alpha if enabled
		if (fadeOut) pSprite.setColor(sf::Color(pSprite.getColor().r, pSprite.getColor().g, pSprite.getColor().b, (float)particles[i].time / (float)lifetime * 255));
		//Apply scale and position to particle
		pSprite.setScale(particles[i].size, particles[i].size);
		pSprite.setPosition(particles[i].position);
		//render
		rW->draw(pSprite);
	}
}