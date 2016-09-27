#include "xp.h"
#include "Spieler.h"


Xp::Xp(float x, float y) : WorldObject(x,y)
{
	speeeeeed = 5;
	amount = 1;
	texture.loadFromFile("Ressources/Graphics/xp.png");
	type = t_playerOnly;
	static_cast<CircleBody*>(body)->setRadius(3);
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
	if (obj->getType() == t_spieler)
	{
		static_cast<Spieler*>(obj)->giveXP(amount);
		flag_destroy = true;
	}
}