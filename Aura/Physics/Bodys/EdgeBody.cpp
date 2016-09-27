#include "EdgeBody.h"

EdgeBody::EdgeBody() : Body()
{
	type = Edge;
	mass = -1;
	isStatic = true;
}

EdgeBody::EdgeBody(float x, float y) : Body(x,y)
{
	type = Edge;
	mass = -1;
	isStatic = true;
}

void EdgeBody::updateAABB()
{
	if(pos.x <= pos.x + p2.x) AABB.left = pos.x;
	else			 AABB.left = pos.x + p2.x;

	if (pos.y <= pos.y + p2.y) AABB.top = pos.y;
	else			  AABB.top = pos.y + p2.y;

	//Note: 0.0001 because otherwise completely diagonal / horizantal lines would have no height/with
	AABB.width = std::fabs(p2.x)+ 0.0001;
	AABB.height = std::fabs(p2.y) + 0.0001;
}

bool EdgeBody::testPoint(sf::Vector2f v)
{
	return false;
}

void EdgeBody::setP2(sf::Vector2f point2)
{
	p2 = point2;
}

sf::Vector2f EdgeBody::getP2()
{
	return p2;
}

void EdgeBody::tick()
{
	Body::tick();
}

void EdgeBody::debugDraw(sf::RenderWindow * rW)
{
	Body::debugDraw(rW);

	sf::VertexArray line;
	line.setPrimitiveType(sf::Lines);
	line.append(pos);
	line.append(pos + p2);

	line[0].color = sf::Color::Yellow;
	line[1].color = sf::Color::Yellow;

	rW->draw(line);
}