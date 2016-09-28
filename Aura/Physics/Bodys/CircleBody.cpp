#include "CircleBody.h"

CircleBody::CircleBody() : Body()
{
	type = Circle;
	radius = 20;
}

void CircleBody::updateAABB()
{
	aabb.left = pos.x - radius - 1;
	aabb.top = pos.y - radius - 1;
	aabb.width = radius * 2 + 2;
	aabb.height = aabb.width + 2;
}

bool CircleBody::testPoint(sf::Vector2f v)
{
	return false;
}

float CircleBody::getRadius()
{
	return radius;
}


void CircleBody::setRadius(float r)
{
	radius = r;
}

void CircleBody::tick()
{
	Body::tick();
}

void CircleBody::debugDraw(sf::RenderWindow * rW)
{
	Body::debugDraw(rW);

	sf::CircleShape circle;
	circle.setPosition(pos);
	circle.setOrigin(sf::Vector2f(radius,radius));
	circle.setRadius(radius);
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineThickness(2);
	circle.setOutlineColor(sf::Color::Green);

	rW->draw(circle);
}