#ifndef CHAINBODY_H
#define CHAINBODY_H

#include "Body.h"

class ChainBody : public Body
{
private:
	std::vector<sf::Vector2f> points;

public:

	ChainBody();
	bool testPoint(sf::Vector2f v);
	void debugDraw(sf::RenderWindow * rW);
	void updateAABB();
	void setPoints(std::vector<sf::Vector2f> vec);
	void addPoint(sf::Vector2f);
	void clearPoints();
	std::vector<sf::Vector2f> getPoints();


};



#endif
