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
	//rW->draw(sprite);
	for (unsigned int i = 0; i < particles.size(); i++)
	{
		if (fadeOut) pSprite.setColor(sf::Color(pSprite.getColor().r, pSprite.getColor().g, pSprite.getColor().b, (float)particles[i].time / (float)lifetime * 255));
		pSprite.setScale(particles[i].size, particles[i].size);
		pSprite.setPosition(particles[i].position);
		rW->draw(pSprite);
	}
}