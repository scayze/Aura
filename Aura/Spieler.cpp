#include "Spieler.h"
#include "Aura.h"
#include <iostream>
//#include "spielfeld.h"

Spieler::Spieler(float x, float y) : Figur(x,y)
{
	type = t_spieler;
	texture.loadFromImage(RessourceManager::getTexture("Ressources/Graphics/Player.png"));
	animation = Animation(&sprite,6,4);
	sprite.setTextureRect(sf::IntRect(0,0,32,48));
	speed = 5;

	//leveling
	level = 1;
	xp = 0;
	xpUntilNextLevel = 100;

	maxHealthPoints = 1000;
}

void Spieler::init(Spielfeld * spiel)
{
	Figur::init(spiel);
	aura = spielfeld->createObject<Aura>(sprite.getPosition().x,sprite.getPosition().y);

}


void Spieler::tick()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            body->setVel(body->getVel().x,-speed);
            animation.animieren(48,32,48);
            direction = 48;
        }
        else if (direction == 48 || direction == 144)
        {
            if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    body->setVel(body->getVel().x,-speed);
                    body->setVel(speed,body->getVel().y);
                    animation.animieren(48,32,48);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    body->setVel(body->getVel().x,-speed);
                    body->setVel(-speed,body->getVel().y);
                    animation.animieren(48,32,48);
                }
            }
            else
            {
                sprite.setTextureRect(sf::IntRect(96,direction,32,48));
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&!sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            body->setVel(body->getVel().x,speed);
            animation.animieren(144,32,48);
            direction = 144;
        }
        else if (direction == 144 || direction == 48)
        {
            if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                {
                    body->setVel(body->getVel().x,speed);
                    body->setVel(speed,body->getVel().y);
                    animation.animieren(144,32,48);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                {
                    body->setVel(body->getVel().x,speed);
                    body->setVel(-speed,body->getVel().y);
                    animation.animieren(144,32,48);
                }
            }
            else
            {
                sprite.setTextureRect(sf::IntRect(96,direction,32,48));
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Left)&&!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            body->setVel(speed,body->getVel().y);
            animation.animieren(96,32,48);
            direction = 96;
        }
        else if (direction == 96 || direction == 0)
        {
            if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    body->setVel(body->getVel().x,-speed);
                    body->setVel(speed,body->getVel().y);
                    animation.animieren(96,32,48);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    body->setVel(body->getVel().x,speed);
                    body->setVel(speed,body->getVel().y);
                    animation.animieren(96,32,48);
                }
            }
            else
            {
                sprite.setTextureRect(sf::IntRect(96,direction,32,48));
            }
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Right)&&!sf::Keyboard::isKeyPressed(sf::Keyboard::Up)&&!sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            body->setVel(-speed,body->getVel().y);
            animation.animieren(0,32,48);
            direction = 0;
        }
        else if (direction == 0 || direction == 96)
        {
            if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                {
                    body->setVel(body->getVel().x,-speed);
                    body->setVel(-speed,body->getVel().y);
                    animation.animieren(0,32,48);
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                {
                    body->setVel(body->getVel().x,speed);
                    body->setVel(-speed,body->getVel().y);
                    animation.animieren(0,32,48);
                }
            }
            else
            {
                sprite.setTextureRect(sf::IntRect(96,direction,32,48));
            }
        }
    }
    if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        sprite.setTextureRect(sf::IntRect(96,direction,32,48));
    }
	
	aura->getBody()->setPos(body->getPos());
	Figur::tick();


	float speeeeeed = Math::vectorLength(body->getVel());
	if (speeeeeed > speed) body->setVel(Math::vectorSetMagnitude(body->getVel(), speed));
	//float speeeeeed = Math::vectorLength(body->getVel());
	//std::cout <<healthPoints << std::endl;

	if (xp >= xpUntilNextLevel) levelUp();

	//spielfeld->createObject<Aura>(sprite.getPosition().x,sprite.getPosition().y);
}

void Spieler::levelUp()
{
	level++;
	xp = xp - xpUntilNextLevel;
	xpUntilNextLevel = xpUntilNextLevel * 1.3;
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

void Spieler::dealDamage(int n)
{
	if (invincibleTimer <= 0)	aura->setRotspeed(-aura->getRotspeed());
	Figur::dealDamage(n);


}