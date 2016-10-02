#ifndef PHYSICSSYSTEM_H
#define PHYSICSSYSTEM_H

#include <deque>
#include "Bodys/PolygonBody.h"
#include "Bodys/CircleBody.h"
#include "Bodys/ChainBody.h"
#include "Bodys/EdgeBody.h"

enum type : unsigned char;

class PhysicsSystem
{

private:
	std::deque<Body*> bodys;
	sf::Clock tic;
	sf::Clock col;
	int t;


public:


	void tick();
	void debugRender(sf::RenderWindow * rW);
	void addBody(Body * b);

	std::vector<Body*> rayCast(sf::Vector2f pos, sf::Vector2f dir, bodyType bt = (bodyType)-1, type wt = (type)-1);

	bool doCollide(Body * b1, Body *b2);
	void collide(Body * b1, Body *b2, sf::Vector2f pushVector);

	sf::Vector2f circleCollide(CircleBody* circle1 ,CircleBody * circle2);
	sf::Vector2f circleEdgeCollide(CircleBody * circle, EdgeBody * edge);
	sf::Vector2f circlePolygonCollide(CircleBody* circle, PolygonBody* polygon);
	sf::Vector2f circleChainCollide(CircleBody* circle, ChainBody* chain);

	bool LineIntersect(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3);


};

#endif
