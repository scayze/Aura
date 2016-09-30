#ifndef CIRCLEBODY_H
#define CIRCLEBODY_H

#include "Body.h"

class CircleBody : public Body
{
private:

	float radius;

public:
	CircleBody();

	void debugDraw(sf::RenderWindow * rW);

	void updateAABB();
	bool testPoint(sf::Vector2f v);
	bool rayCast(sf::Vector2f pos, sf::Vector2f dir);

	float getRadius();
	void tick();
	void setRadius(float r);
};



#endif