#ifndef MATH_H
#define MATH_H

#include <SFML\System\Vector2.hpp>

class Math
{
private:

public:

	static inline sf::Vector2f vectorNormalize(sf::Vector2f v);
	static inline float vectorLength(sf::Vector2f v);
	static inline float vectorDistance(sf::Vector2f v1, sf::Vector2f v2);
	static inline float vectorSquaredDistance(sf::Vector2f v1, sf::Vector2f v2);
	static inline sf::Vector2f vectorSetMagnitude(sf::Vector2f, float magnitude);
	static inline float vectorDot(sf::Vector2f v1, sf::Vector2f v2);
	static inline float vectorProjectOn(sf::Vector2f v1, sf::Vector2f axis);
	static inline sf::Vector2f vectorRotateAroundPoint(sf::Vector2f p, sf::Vector2f pivot, float angle);
	static inline float vectorGetRotation(sf::Vector2f p);
	static inline float PI();

};


#endif 
