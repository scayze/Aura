#include "Laser.h"
#include "Spieler.h"

Laser::Laser(float x, float y) : WorldObject(x, y)
{
	type = t_noCollide;
	delete body;
	body = new EdgeBody();
	body->setPos(x, y);
	body->setMass(-1);

	texture.loadFromFile("Ressources/Graphics/Laser.png");
	sprite.setScale(350, 1);

	ticksUntilDamage = 15;
}

void Laser::init(Spielfeld * s)
{
	WorldObject::init(s);
	sprite.setOrigin(1, sprite.getLocalBounds().height / 2);
}

void Laser::tick()
{
	ticksUntilDamage--;
	if (ticksUntilDamage == 0)
	{
		type = t_gegner;
	}
	if (ticksUntilDamage < 0) flag_destroy = true;
	WorldObject::tick();
	body->tick();
}

void Laser::collide(WorldObject * object)
{

	if (object->getType() == t_spieler)
	{
		static_cast<Figur*>(object)->dealDamage(200);
	}
}