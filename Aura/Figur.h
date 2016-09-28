#ifndef FIGUR_H
#define FIGUR_H

#include "WorldObject.h"

class Figur : public WorldObject
{
protected:

	//std::vector<Buff*> buffs;
	int maxHealthPoints;
	int healthPoints;

	int invincibleTimer = 0;
	int timeInvincible = 30;

	float speed;
	int xpDrop;


public:
	Figur(float x, float y);
	virtual void tick();
	virtual void init(Spielfeld * spielfeld);

	virtual void dealDamage(int n);
	void heal(int n);

	int getHealthPoints();
	int getMaxHealth();
	virtual ~Figur();
};

#endif