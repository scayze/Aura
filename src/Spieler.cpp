#include "Spieler.h"
#include "Aura.h"
#include <iostream>
//#include "spielfeld.h"

Spieler::Spieler(float x, float y) : Figur(x,y)
{
	Resources::loadTexture(texLeft,"Player/player_left.png");
	Resources::loadTexture(texUp,"Player/player_up.png");
	Resources::loadTexture(texDown,"Player/player_down.png");
	Resources::loadTexture(texRight,"Player/player_right.png");

    sprLeft.setTexture(texLeft);
    sprUp.setTexture(texUp);
    sprDown.setTexture(texDown);
    sprRight.setTexture(texRight);

    sprLeft.setOrigin(sf::Vector2f(16,24));
    sprUp.setOrigin(sf::Vector2f(16,24));
    sprDown.setOrigin(sf::Vector2f(16,24));
    sprRight.setOrigin(sf::Vector2f(16,24));

	animation = Animation(&sprDown,7,32,48,7);

	body->setCollisionType(t_spieler);
	static_cast<CircleBody*>(body)->setRadius(15);
	speed = 5;

	//leveling
	level = 1;
	xp = 0;
	xpUntilNextLevel = 100;

	maxHealthPoints = 10000;
}

void Spieler::init(Spielfeld * spiel)
{
	Figur::init(spiel);
	aura = spielfeld->createObject<Aura>(sprite.getPosition().x,sprite.getPosition().y);

}


void Spieler::tick()
{
    sf::Vector2f joyPos;
	if(sf::Joystick::isConnected(0))
    {

        joyPos.x = sf::Joystick::getAxisPosition(0, sf::Joystick::X) / 100;
        joyPos.y = sf::Joystick::getAxisPosition(0, sf::Joystick::Y) / 100;
        //std::cout << x << "   " << y << std::endl;
        body->setVel(sf::Vector2f(speed * joyPos.x,speed * joyPos.y));
    }

    animation.setSpeed(Math::vectorLength(joyPos));
	animation.tick();
	aura->getBody()->setPos(body->getPos());
	Figur::tick();


	float speeeeeed = Math::vectorLength(body->getVel());
	if (speeeeeed > speed) body->setVel(Math::vectorSetMagnitude(body->getVel(), speed));
	//float speeeeeed = Math::vectorLength(body->getVel());
	//std::cout <<healthPoints << std::endl;

	if (xp >= xpUntilNextLevel) levelUp();

	//spielfeld->createObject<Aura>(sprite.getPosition().x,sprite.getPosition().y);
}

void Spieler::render(sf::RenderWindow * rW)
{
    dir direction = Math::vectorGetDirection(body->getVel());
    if(direction != oldDirection)
    {
        if(direction==DIR_LEFT) animation.changeSprite(&sprLeft);
        else if(direction==DIR_UP) animation.changeSprite(&sprUp);
        else if(direction==DIR_RIGHT) animation.changeSprite(&sprRight);
        else if(direction==DIR_DOWN) animation.changeSprite(&sprDown);
        oldDirection = direction;
    }

    animation.getSprite()->setPosition(body->getPos());
    rW->draw(*animation.getSprite());
}

void Spieler::levelUp()
{
	level++;
	xp = xp - xpUntilNextLevel;
	xpUntilNextLevel = xpUntilNextLevel * 1.3f;
}

Aura * Spieler::getAura()
{
	return aura;
}

int Spieler::getLevel()
{
	return level;
}

void Spieler::giveXP(int n)
{
	xp += n;
}

int Spieler::getXP()
{
	return xp;
}

int Spieler::getXpNeeded()
{
	return xpUntilNextLevel;
}


void Spieler::collide(WorldObject *obj)
{

}