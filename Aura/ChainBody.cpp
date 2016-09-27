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
		if (points[i].x < AABB.left) AABB.left = points[i].x;
		if (points[i].y < AABB.top) AABB.top = points[i].y;

		if (points[i].x > right) right = points[i].x;
		if (points[i].y > down) down = points[i].y;
	}

	AABB.width = right - AABB.left + 2;
	AABB.height = down - AABB.top + 2;

	AABB.left = AABB.left + pos.x - 1;
	AABB.top = AABB.top + pos.y - 1;
}

bool ChainBody::testPoint(sf::Vector2f v)
{
	return false;
}