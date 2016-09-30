#ifndef MATH_H
#define MATH_H

#include <SFML\System\Vector2.hpp>
#include <cmath>

class Math
{
private:

public:

	static inline sf::Vector2f vectorNormalize(sf::Vector2f v);
	static inline float vectorLength(sf::Vector2f v);
	static inline float vectorDistance(sf::Vector2f v1, sf::Vector2f v2);
	static inline float vectorSquaredDistance(sf::Vector2f v1, sf::Vector2f v2);
	static inline sf::Vector2f vectorSetMagnitude(sf::Vector2f, float magnitude);
	static inline float vectorCross(sf::Vector2f v1, sf::Vector2f v2);
	static inline float vectorDot(sf::Vector2f v1, sf::Vector2f v2);
	static inline float vectorProjectOn(sf::Vector2f v1, sf::Vector2f axis);
	static inline sf::Vector2f vectorRotateAroundPoint(sf::Vector2f p, sf::Vector2f pivot, float angle);
	static inline float vectorGetRotation(sf::Vector2f p);
	static inline float PI();

};

//Get die Distanz zwischen zwei vektoren
float Math::vectorDistance(sf::Vector2f v1, sf::Vector2f v2)
{
	//Satz Pythagoras
	return std::sqrt(std::fabs((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y)));
}

//Get die Länge des Vektors quadriert
float Math::vectorSquaredDistance(sf::Vector2f v1, sf::Vector2f v2)
{
	//Satz Pythagoras -  sqrt
	return std::fabs((v1.x - v2.x) * (v1.x - v2.x) + (v1.y - v2.y) * (v1.y - v2.y));
}

//Get die Länge des Vektors
float Math::vectorLength(sf::Vector2f v)
{
	return std::sqrt(v.x * v.x + v.y * v.y);
}

//Bringe Vektor auf die Länge 1
sf::Vector2f Math::vectorNormalize(sf::Vector2f v)
{
	float length = std::sqrt(v.x * v.x + v.y * v.y);
	v.x = v.x / length;
	v.y = v.y / length;

	return v;
}

//Bringe VEktor auf gewünschte Länge
sf::Vector2f Math::vectorSetMagnitude(sf::Vector2f v, float m)
{
	float length = std::sqrt(v.x * v.x + v.y * v.y);
	v.x = v.x / length * m;
	v.y = v.y / length * m;

	return v;
}

//Dot Product of two vectors
float Math::vectorDot(sf::Vector2f v1, sf::Vector2f v2)
{
	return v1.x * v2.x + v1.y * v2.y;
}

//Cross Product of two vectors
float Math::vectorCross(sf::Vector2f v1, sf::Vector2f v2)
{
	return v1.x * v2.y - v1.y * v2.x;
}


//Project a Vector on an axis and return the length of the projected vector
float Math::vectorProjectOn(sf::Vector2f v, sf::Vector2f axis)
{
	return vectorDot(v, vectorNormalize(axis));
}

//Rotate Point around another point
sf::Vector2f Math::vectorRotateAroundPoint(sf::Vector2f p, sf::Vector2f pivot, float angle)
{
	return sf::Vector2f(
		cos(angle) * (p.x - pivot.x) - sin(angle) * (p.y - pivot.y) + pivot.x,
		sin(angle) * (p.x - pivot.x) + cos(angle) * (p.y - pivot.y) + pivot.y
	);
}

//Get Rotation of vector (from (0|0))
float Math::vectorGetRotation(sf::Vector2f p)
{
	return atan2(p.y, p.x);
}

//Get den Wert von PI
float Math::PI()
{
	return 3.14159265359f;
}


#endif 
