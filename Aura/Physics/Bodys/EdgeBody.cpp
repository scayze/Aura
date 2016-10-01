#include "EdgeBody.h"

EdgeBody::EdgeBody() : Body()
{
	bodyType = Edge;
	mass = -1;
	isStatic = true;
}

EdgeBody::EdgeBody(float x, float y) : Body(x,y)
{
	bodyType = Edge;
	mass = -1;
	isStatic = true;
}

void EdgeBody::updateAABB()
{
	if(pos.x <= pos.x + p2.x) aabb.left = pos.x;
	else			 aabb.left = pos.x + p2.x;

	if (pos.y <= pos.y + p2.y) aabb.top = pos.y;
	else			  aabb.top = pos.y + p2.y;

	//Note: 0.0001 because otherwise completely diagonal / horizantal lines would have no height/with
	aabb.width = std::fabs(p2.x)+ 0.0001;
	aabb.height = std::fabs(p2.y) + 0.0001;
}

bool EdgeBody::testPoint(sf::Vector2f v)
{
	return false;
}

bool EdgeBody::rayCast(sf::Vector2f position, sf::Vector2f dir)
{

	sf::Vector2f v1 = position - pos;
	sf::Vector2f v2 = p2;
	sf::Vector2f v3 = sf::Vector2f(-dir.y, dir.x);

	float dot = Math::vectorDot(v2, v3);

	float t1 = Math::vectorCross(v2, v1) / dot;
	float t2 = Math::vectorDot(v1, v3) / dot;

	if (t1 >= 0.f && (t2 >= 0.f && t2 <= 1.f))
		return true;// t1;

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