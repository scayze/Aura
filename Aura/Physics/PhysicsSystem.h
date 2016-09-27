#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include <deque>
#include "Bodys/PolygonBody.h"
#include "Bodys/CircleBody.h"
#include "Bodys/ChainBody.h"
#include "Bodys/EdgeBody.h"

class PhysicsSystem
{

private:
	std::deque<Body*> bodys;


public:


	void tick();
	void debugRender(sf::RenderWindow * rW);
	void addBody(Body * b);

	bool doCollide(Body * b1, Body *b2);
	void collide(Body * b1, Body *b2, sf::Vector2f pushVector);

	sf::Vector2f circleCollide(CircleBody* circle1 ,CircleBody * circle2);
	sf::Vector2f circleEdgeCollide(CircleBody * circle, EdgeBody * edge);
	sf::Vector2f circlePolygonCollide(CircleBody* circle, PolygonBody* polygon);
	sf::Vector2f circleChainCollide(CircleBody* circle, ChainBody* chain);

	bool LineIntersect(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3);


};

#endif
