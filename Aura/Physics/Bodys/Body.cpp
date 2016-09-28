#include "Body.h"

Body::Body()
{
	pos.x = 0;
	pos.y = 0;
	mass = 10;
	type = Circle;
	isStatic = false;
	owner = NULL;
}

Body::Body(float xpos,float ypos)
{
	pos.x = xpos;
	pos.y = ypos;
	mass = 10;
	type = Circle;
}

void Body::tick()
{
	vel.x /= 1.2f;
	vel.y /= 1.2f;
	pos+=vel;
	updateAABB();
}

int Body::getType()
{
	return type;
}

//Dimensions get & sets
int Body::getMass()
{
	return mass;
}

void Body::setMass(int m)
{
	mass = m;
}

//Position get & sets
sf::Vector2f Body::getPos()
{
    return pos;
}

void Body::setPos(float x, float y)
{
	pos.x = x;
	pos.y = y;
	updateAABB();
}

void Body::setPos(sf::Vector2f vec)
{
	pos.x = vec.x;
	pos.y = vec.y;
	updateAABB();
}

//Velocity get & sets
sf::Vector2f Body::getVel()
{
    return vel;
}

void Body::setVel(float x, float y)
{
	vel.x = x;
	vel.y = y;
}

void Body::setVel(sf::Vector2f vec)
{
	vel.x = vec.x;
	vel.y = vec.y;
}

void * Body::getOwner()
{
	return owner;
}

void Body::setOwner(void * o)
{
	owner = o;
}

AABB& Body::getAABB()
{
	return aabb;
}

void Body::debugDraw(sf::RenderWindow * rW)
{

	//sf::RectangleShape rec;
	//rec.setPosition(sf::Vector2f(AABB.left, AABB.top));
	//rec.setOutlineThickness(2);
	//rec.setFillColor(sf::Color::Transparent);
	//rec.setOutlineColor(sf::Color::Yellow);
	//rec.setSize(sf::Vector2f(AABB.width, AABB.height));

	//rW->draw(rec);
}