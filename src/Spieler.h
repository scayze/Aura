#ifndef SPIELER_H
#define SPIELER_H

#include "Figur.h"
#include "Aura.h"
#include "Animation.h"

class Spieler : public Figur
{
	private:
		Aura * aura;
		Animation animation;

		sf::Sprite sprLeft;
		sf::Texture texLeft;

		sf::Sprite sprUp;
		sf::Texture texUp;

		sf::Sprite sprRight;
		sf::Texture texRight;

		sf::Sprite sprDown;
		sf::Texture texDown;

		int level;

		int xpUntilNextLevel;
		int xp;

		void levelUp();

		dir oldDirection;


	public:
		Spieler(float x, float y);
		void init(Spielfeld * spiel);
		void tick();
		void render(sf::RenderWindow * rW);

		void collide(WorldObject *obj);
		void giveXP(int n);
		int getXP();
		int getXpNeeded();
		Aura * getAura();
		int getLevel();
};

#endif