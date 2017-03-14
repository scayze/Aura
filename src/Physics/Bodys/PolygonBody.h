#ifndef POLYGONBODY_H
#define POLYGONBODY_H

#include "Body.h"

class PolygonBody : public Body
{
	private:
		std::vector<sf::Vector2f> points;
		sf::Vector2f centerOfMass;

	public:

		PolygonBody();
		void debugDraw(sf::RenderWindow * rW);
		void updateAABB();
		bool testPoint(sf::Vector2f v);
		float rayCast(sf::Vector2f pos, sf::Vector2f dir);

		void updateCenterOfMass();
		void setPoints(std::vector<sf::Vector2f> vec);
		void addPoint(sf::Vector2f);
		void clearPoints();
		std::vector<sf::Vector2f>& getPoints();


};



#endif
