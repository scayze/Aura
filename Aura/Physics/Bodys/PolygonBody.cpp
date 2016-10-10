#include "PolygonBody.h"

PolygonBody::PolygonBody() : Body()
{
	bodyType = Polygon;
	isStatic = true;
}

void PolygonBody::debugDraw(sf::RenderWindow * rW)
{
	Body::debugDraw(rW);
}

void PolygonBody::clearPoints()
{
	points.clear();
}

void PolygonBody::addPoint(sf::Vector2f vec)
{
	points.push_back(vec);

	updateAABB();
}

std::vector<sf::Vector2f>& PolygonBody::getPoints()
{
	return points;
}

void PolygonBody::setPoints(std::vector<sf::Vector2f> vec)
{
	points.clear();
	points = vec;

	updateAABB();
}

void PolygonBody::updateAABB()
{
	float right = 0;
	float down = 0;

	for (unsigned int i = 0; i < points.size(); i++)
	{
		if (points[i].x < aabb.left) aabb.left = points[i].x;
		if (points[i].y < aabb.top) aabb.top = points[i].y;

		if (points[i].x > right) right = points[i].x;
		if (points[i].y > down) down = points[i].y;
	}

	aabb.width = right - aabb.left + 2;
	aabb.height = down - aabb.top + 2;

	aabb.left = aabb.left + pos.x -1;
	aabb.top = aabb.top + pos.y -1 ;


}

bool PolygonBody::testPoint(sf::Vector2f v)
{
	return false;
}

float PolygonBody::rayCast(sf::Vector2f pos, sf::Vector2f dir)
{
	return false;
}

void PolygonBody::updateCenterOfMass()
{

}