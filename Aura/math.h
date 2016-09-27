#ifndef MATH_H
#define MATH_H

#include <SFML\System\Vector2.hpp>

class Math
{
private:

public:

	static sf::Vector2f vectorNormalize(sf::Vector2f v);
	static float vectorLength(sf::Vector2f v);
	static float vectorDistance(sf::Vector2f v1, sf::Vector2f v2);
	static float vectorSquaredDistance(sf::Vector2f v1, sf::Vector2f v2);
	static sf::Vector2f vectorSetMagnitude(sf::Vector2f, float magnitude);
	static float vectorDot(sf::Vector2f v1, sf::Vector2f v2);
	static float vectorProjectOn(sf::Vector2f v1, sf::Vector2f axis);
	static sf::Vector2f vectorRotateAroundPoint(sf::Vector2f p, sf::Vector2f pivot, float angle);
	static float vectorGetRotation(sf::Vector2f p);
	static float PI();

};


#endif 
