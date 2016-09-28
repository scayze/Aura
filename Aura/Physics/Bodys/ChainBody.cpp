#include "ChainBody.h"

ChainBody::ChainBody() : Body()
{
	type = Chain;
	isStatic = true;
}

void ChainBody::debugDraw(sf::RenderWindow * rW)
{
	Body::debugDraw(rW);
}

void ChainBody::clearPoints()
{
	points.clear();
}

void ChainBody::addPoint(sf::Vector2f vec)
{
	points.push_back(vec);

	updateAABB();
}

std::vector<sf::Vector2f> ChainBody::getPoints()
{
	return points;
}

void ChainBody::setPoints(std::vector<sf::Vector2f> vec)
{
	points.clear();
	points = vec;

	updateAABB();
}

void ChainBody::updateAABB()
{
	float right = 0;
	float down = 0;

	for (int i = 0; i < points.size(); i++)
	{
		if (points[i].x < aabb.left) aabb.left = points[i].x;
		if (points[i].y < aabb.top) aabb.top = points[i].y;

		if (points[i].x > right) right = points[i].x;
		if (points[i].y > down) down = points[i].y;
	}

	aabb.width = right - aabb.left + 2;
	aabb.height = down - aabb.top + 2;

	aabb.left = aabb.left + pos.x - 1;
	aabb.top = aabb.top + pos.y - 1;
}

bool ChainBody::testPoint(sf::Vector2f v)
{
	return false;
}