#include "xp.h"
#include "Spieler.h"


Xp::Xp(float x, float y) : WorldObject(x,y)
{
	speeeeeed = 6;
	amount = 1;
	Resources::loadTexture(texture,"xp.png");
	static_cast<CircleBody*>(body)->setRadius(3);
	body->addCollisionWith(t_spieler);
}

void Xp::tick()
{
	WorldObject::tick();
	body->setVel(Math::vectorSetMagnitude(spielfeld->getPlayer()->getBody()->getPos() - body->getPos(), speeeeeed));
}


void Xp::setAmount(int n)
{
	amount = n;
}

void Xp::collide(WorldObject * obj)
{
	if (obj->getBody()->getCollisionType() == t_spieler)
	{
		static_cast<Spieler*>(obj)->giveXP(amount);
		flag_destroy = true;
	}
}