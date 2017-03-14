#include "Figur.h"
#include "xp.h"

Figur::Figur(float x, float y) : WorldObject(x, y)
{
	maxHealthPoints = 25;

	xpDrop = 25;
	body->setCollisionWith(t_terrain);
}

void Figur::init(Spielfeld * s)
{
	WorldObject::init(s);
	healthPoints = maxHealthPoints;
}

void Figur::dealDamage(int n)
{
	if (invincibleTimer <= 0)
	{
		healthPoints -= n;
		invincibleTimer = timeInvincible;
	}
	
}

void Figur::tick()
{
	WorldObject::tick();

	invincibleTimer--;

	//Red flashing
	if (invincibleTimer >= 0)
	{
		int * n = new int;
		//tweeny::from(4).to(9)
		sprite.setColor(sf::Color(255, 255 - invincibleTimer * 9, 255 - invincibleTimer * 9));
	}

	//destruction
	if (healthPoints <= 0) flag_destroy = true;
}

void Figur::heal(int n)
{
	if(healthPoints + n <= maxHealthPoints) healthPoints += n;
	else healthPoints = maxHealthPoints;
}

int Figur::getHealthPoints()
{
	return healthPoints;
}

int Figur::getMaxHealth()
{
	return maxHealthPoints;
}

bool Figur::isInvincible()
{
	return invincibleTimer > 0;
}


Figur::~Figur()
{
	Xp * x = spielfeld->createObject<Xp>(body->getPos().x, body->getPos().y);
	x->setAmount(xpDrop);
}