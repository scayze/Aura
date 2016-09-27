#ifndef EDGEBODY_H
#define EDGEBODY_H

#include "Body.h"

class EdgeBody : public Body
{
private:

	sf::Vector2f p2;

public:
	EdgeBody();
	EdgeBody(float x, float y);

	void debugDraw(sf::RenderWindow * rW);

	void updateAABB();

	bool testPoint(sf::Vector2f v);

	void setP2(sf::Vector2f p2);
	sf::Vector2f getP2();

	void tick();

};



#endif