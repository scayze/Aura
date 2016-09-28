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
		int direction;
		int level;

		int xpUntilNextLevel;
		int xp;

		void levelUp();


	public:
		Spieler(float x, float y);
		void init(Spielfeld * spiel);
		void tick();

		void dealDamage(int n);

		void giveXP(int n);
		int getXP();
		int getXpNeeded();
		Aura * getAura();
		int getLevel();
};

#endif