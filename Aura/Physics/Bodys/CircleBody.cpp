#include "CircleBody.h"

CircleBody::CircleBody() : Body()
{
	bodyType = Circle;
	radius = 10;
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

bool CircleBody::rayCast(sf::Vector2f position, sf::Vector2f dir)
{

	sf::Vector2f p1(position);
	sf::Vector2f p2(position +dir);
	sf::Vector2f p3(pos);

	//Vektor von p1 nach p3;
	sf::Vector2f vP1_P3(p3.x - p1.x, p3.y - p1.y);
	//Vektor von P1 nach P2;
	sf::Vector2f vP1_P2(p2.x - p1.x, p2.y - p1.y);
	//Vektor vP1_P2 normalisiert
	sf::Vector2f vP1_P2_norm = Math::vectorNormalize(vP1_P2);
	//Vektor vP1_P2_norm um nach links gedreht ( 90° )
	sf::Vector2f vP1_P2_leftnorm(-vP1_P2_norm.y, vP1_P2_norm.x);

	//Länge des Vektors vP1_P2 auf vP1_P2_leftnorm projektiert
	float projectedOnNormal = Math::vectorProjectOn(vP1_P3, vP1_P2_leftnorm);
	//Länge des Vektors vP1_P2 auf vP1_P2_norm projektiert
	float projectedOnP1P2 = Math::vectorProjectOn(vP1_P3, vP1_P2_norm);

	if (
		//Wenn der auf vP1_P2_leftnorm projektierte vektor kleiner ist als der Radius des Kreises
		std::fabs(projectedOnNormal) < radius
		//Und das Dot Produkt größer als null ist ( Winkel kleiner 90° )
		&& Math::vectorDot(vP1_P2, vP1_P3) > 0
		)
	{

		return true;
	}

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