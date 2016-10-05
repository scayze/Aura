#include "LaserBox.h"
#include "Spieler.h"

LaserBox::LaserBox(float x, float y) : Gegner(x, y)
{
	Resources::loadTexture(texture,"LaserBox.png");
	sprite.setScale(1.5, 1.5);

	range = 350;
	timeBetweenShots = 180;
	chargeTime = 30;
	timer = timeBetweenShots;

	maxHealthPoints = 20;

	static_cast<CircleBody*>(body)->setRadius(8);
	body->setMass(40);

}

void LaserBox::init(Spielfeld * s)
{
	Gegner::init(s);
}

void LaserBox::tick()
{
	Gegner::tick();
	timer--;
	if (timer == chargeTime)
	{
		Resources::loadTexture(texture,"LaserBoxFireing.png");

		if (!(Math::vectorSquaredDistance(body->getPos(), spielfeld->getPlayer()->getBody()->getPos()) < range * range))
		{
			timer++;
		}
	}
	if (timer == chargeTime/2)		dir = spielfeld->getPlayer()->getBody()->getPos() - body->getPos();
	if (timer == 0)
	{

		timer = timeBetweenShots;
		fireLaser();
		Resources::loadTexture(texture,"LaserBox.png");

	}
}

void LaserBox::fireLaser()
{
	//spielfeld->getPlayer()
	Laser * laser = spielfeld->createObject<Laser>(body->getPos().x, body->getPos().y);

	static_cast<EdgeBody*>(laser->getBody())->setP2(Math::vectorSetMagnitude(dir, range));
	laser->getSprite().setRotation(180 + (Math::vectorGetRotation(dir) * 180.f / Math::PI()));
}