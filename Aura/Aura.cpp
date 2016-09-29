#include "Aura.h"
#include "Figur.h"

Aura::Aura(float x, float y) : WorldObject(x,y)
{
    type = t_aura;
	Resources::loadTexture(texture,"Sword.png");
    rotspd = 8;

	delete body;
	body = new EdgeBody();
	body->setPos(x, y);
	body->setMass(-1);

}

void Aura::init(Spielfeld * spiel)
{
	WorldObject::init(spiel);
    sprite.setOrigin(-32,sprite.getGlobalBounds().height/2);
	//static_cast<CircleBody*>(body)->setRadius(80);
	static_cast<EdgeBody*>(body)->setP2(sf::Vector2f(body->getPos().x + 80, body->getPos().y));
}

void Aura::tick()
{
	WorldObject::tick();
	sprite.setRotation(sprite.getRotation()+rotspd);
	EdgeBody * b = static_cast<EdgeBody*>(body);

	b->setP2(Math::vectorRotateAroundPoint(b->getP2(), sf::Vector2f(0,0), rotspd / 180.f * Math::PI()));
}

void Aura::collide(WorldObject * object)
{
	if (object->getType() == t_gegner)
	{
		static_cast<Figur*>(object)->dealDamage(damage);
		rotspd = -rotspd;
	}
}

float Aura::getRotspeed()
{
	return rotspd;
}
void Aura::setRotspeed(float rs)
{
	rotspd = rs;
}