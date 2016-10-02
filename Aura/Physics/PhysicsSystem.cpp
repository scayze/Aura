#include "PhysicsSystem.h"
#include "../Worldobject.h"
#include <iostream>

void PhysicsSystem::addBody(Body * b)
{
	if (!b->isStatic)
		bodys.push_front(b);
	else bodys.push_back(b);
}

void PhysicsSystem::debugRender(sf::RenderWindow * rW)
{
	for (unsigned int i = 0; i < bodys.size(); i++)
	{
		bodys[i]->debugDraw(rW);

	}
}

void PhysicsSystem::tick()
{
	t = 0;
	for (unsigned int i = 0; i < bodys.size(); i++)
	{
		if (bodys[i]->flagDestroy)
		{
			delete bodys[i];
			bodys.erase(bodys.begin() + i);
		}
	}

	for (unsigned int i = 0; i < bodys.size(); i++)
	{
		if (!bodys[i]->isStatic) bodys[i]->tick();
	}


	//Loop durch alle Körper
	for (unsigned int i = 0; i < bodys.size(); i++)
	{
		//Wenn es ein statischer körper ist, breche ab
		if (bodys[i]->isStatic) break;

		//Loop durch alle anderen Körper
		for (unsigned int j = i + 1; j < bodys.size(); j++)
		{
			//Wenn die Körper nicht Kollidieren sollen, gehe zur nächsten loop iteration
			if (!doCollide(bodys[i], bodys[j])) continue;

			//Wenn die AABBs der Körper sich überschneiden
			if (bodys[i]->getAABB().intersects(bodys[j]->getAABB()))
			{
				//Vektor um den sich die Körper von einander entfernen sollen
				sf::Vector2f pushVector;

				//Wenn beide Körper Kreise sind
				if(bodys[i]->getType() == Circle && bodys[j]->getType() == Circle)
				//if ( (bodys[i]->getType() ^ bodys[j]->getType()) == (Circle ^ Circle))
				{
					//Setze pushvektor

					pushVector = circleCollide((CircleBody*)bodys[i], (CircleBody*)bodys[j]);

					//Wenn pushvektor nicht Null ist, dann lasse sie kollidieren
					if (! (pushVector.x == NULL && pushVector.y == NULL)) collide(bodys[i], bodys[j], pushVector);
				}

				//Wenn ein Körper Kreis und der andere eine Linie ist
				else if (bodys[i]->getType() == Circle && bodys[j]->getType() == Edge || bodys[i]->getType() == Edge && bodys[j]->getType() == Circle)
				//else if ((bodys[i]->getType() ^ bodys[j]->getType()) == (Circle ^ Edge))
				{

					if (bodys[i]->getType() == Circle) pushVector = circleEdgeCollide((CircleBody*)bodys[i], (EdgeBody*)bodys[j]);
					else							   pushVector = circleEdgeCollide((CircleBody*)bodys[j], (EdgeBody*)bodys[i]);

					if (!(pushVector.y == NULL && pushVector.x == NULL))
					{
						if (bodys[i]->getType() == Circle)	collide(bodys[i], bodys[j], pushVector);
						else								collide(bodys[j], bodys[i], pushVector);
					}
				}

				//Wenn ein Körper Kreis und der andere ein Polygon ist
				else if (bodys[i]->getType() == Circle && bodys[j]->getType() == Polygon || bodys[i]->getType() == Polygon && bodys[j]->getType() == Circle)
				//else if ( (bodys[i]->getType() ^ bodys[j]->getType()) == (Circle ^ Polygon))
				{
					if(bodys[i]->getType() == Circle) pushVector = circlePolygonCollide((CircleBody*)bodys[i], (PolygonBody*)bodys[j]);
					else							  pushVector = circlePolygonCollide((CircleBody*)bodys[j], (PolygonBody*)bodys[i]);

					if (!(pushVector.y == NULL && pushVector.x ==NULL))
					{
						if (bodys[i]->getType() == Circle)	collide(bodys[i], bodys[j], pushVector);
						else								collide(bodys[j], bodys[i], pushVector);
					}
				}

				//Wenn ein Körper Kreis und der andere eine Chain ist
				else if (bodys[i]->getType() == Circle && bodys[j]->getType() == Chain || bodys[i]->getType() == Chain && bodys[j]->getType() == Circle)
				//else if ((bodys[i]->getType() ^ bodys[j]->getType()) == (Circle ^ Chain))
				{
					if (bodys[i]->getType() == Circle) pushVector = circleChainCollide((CircleBody*)bodys[i], (ChainBody*)bodys[j]);
					else							   pushVector = circleChainCollide((CircleBody*)bodys[j], (ChainBody*)bodys[i]);

					if (!(pushVector.y == NULL && pushVector.x == NULL))
					{
						if (bodys[i]->getType() == Circle)	collide(bodys[i], bodys[j], pushVector);
						else								collide(bodys[j], bodys[i], pushVector);
					}
				}
			}
		}
	}
	//std::cout << "Collision: " << t << std::endl;// col.getElapsedTime().asMicroseconds() << std::endl;
}

void PhysicsSystem::collide(Body * b1, Body * b2, sf::Vector2f pushVector)
{
	//Let the Objects know they are colliding
	WorldObject * w1 = static_cast<WorldObject*>(b1->getOwner());
	WorldObject * w2 = static_cast<WorldObject*>(b2->getOwner());
	
	if (w1 && w2)
	{
		w1->collide(w2);
		w2->collide(w1);
	}

	if (b1->getMass() < 0 || b2->getMass() < 0) return;
	if (b1->isStatic)
	{
		b2->setPos(b2->getPos() - pushVector);
		return;
	}
	else if (b2->isStatic)
	{
		b1->setPos(b1->getPos() + pushVector);
		return;
	}

	//Deklariere neue teilvektoren für beide objekte die angeben in
	//welchen verhältnis ( in abhängigkeit von der masse ) die objekte sich jeweils vom anderen entfernen
	//teile den Vektor um die masse die bei der kollision im spiel ist
	pushVector.x = pushVector.x / (b1->getMass() + b2->getMass());
	pushVector.y = pushVector.y / (b1->getMass() + b2->getMass());

	sf::Vector2f vec1(pushVector);
	vec1.x = vec1.x * b2->getMass();
	vec1.y = vec1.y * b2->getMass();

	sf::Vector2f vec2(pushVector);
	vec2.x = vec2.x * b1->getMass();
	vec2.y = vec2.y * b1->getMass();

	//verschiebe Objekte um errechnete vektoren
	b1->setPos(b1->getPos() + vec1);
	b2->setPos(b2->getPos() - vec2);
}

bool PhysicsSystem::doCollide(Body * b1, Body *b2)
{

	if ((b1->getCollisionType() & b2->getCollisionWith() | b1->getCollisionWith() & b2->getCollisionType()) != 0b0000000) return true;
	return false;
}

sf::Vector2f PhysicsSystem::circleCollide(CircleBody* b1, CircleBody* b2)
{
	//Check if circles are even colliding

	//Distance
	//float dist = Math::vectorDistance(b1->getPos(), b2->getPos());
	float xdist = b1->getPos().x - b2->getPos().x;
	float ydist = b1->getPos().y - b2->getPos().y;
	float dist = xdist*xdist + ydist*ydist;
	//Return true if the sum of the radians squared is smaller than the distance between the objects squared
	float sumradius = b1->getRadius() + b2->getRadius();
	if (sumradius*sumradius < dist) return sf::Vector2f(NULL,NULL);

	//Der Vektor um die die Objecte von einander entfernt werden müssen um nicht mehr zu kollidiern
	sf::Vector2f pushVector;

	pushVector.x = xdist;
	pushVector.y = ydist;

	//Errechne distanz
	float distance = Math::vectorDistance(b1->getPos(), b2->getPos());

	//Errechne die entfernung mit der sich die kreise überlappen
	float insideDistance = sumradius - distance;

	//Errechne pushVektor
	pushVector.x = pushVector.x / distance * insideDistance;
	pushVector.y = pushVector.y / distance * insideDistance;

	return pushVector;
}

sf::Vector2f PhysicsSystem::circleEdgeCollide(CircleBody * circle, EdgeBody * edge)
{

	sf::Vector2f p1(edge->getPos());
	sf::Vector2f p2(p1 + edge->getP2());
	sf::Vector2f p3(circle->getPos());

	//Vektor von p1 nach p3;
	sf::Vector2f vP1_P3(p3.x - p1.x, p3.y - p1.y);
	//Vektor von P1 nach P2;
	sf::Vector2f vP1_P2(p2.x - p1.x, p2.y - p1.y);
	//Vektor vP1_P2 normalisiert
	sf::Vector2f vP1_P2_norm = Math::vectorNormalize(vP1_P2);
	//Vektor vP1_P2_norm um nach links gedreht ( 90° )
	sf::Vector2f vP1_P2_leftnorm(-vP1_P2_norm.y, vP1_P2_norm.x);

	//Länge des Vektors vP1_P2 auf vP1_P2_leftnorm projektiert
	float projectedOnNormal = Math::vectorProjectOn(vP1_P3, vP1_P2_leftnorm);
	//Länge des Vektors vP1_P2 auf vP1_P2_norm projektiert
	float projectedOnP1P2 = Math::vectorProjectOn(vP1_P3, vP1_P2_norm);

	if (

		//Wenn der auf vP1_P2_leftnorm projektierte vektor kleiner ist als der Radius des Kreises
		std::fabs(projectedOnNormal) < circle->getRadius()
		//Und das Dot Produkt größer als null ist
		&& Math::vectorDot(vP1_P2, vP1_P3) > 0
		//Und der auf vP1_P2_norm projektierte vektor kleiner ist als die länge der Linie zwischen P1 und P2
		&& projectedOnP1P2 < Math::vectorLength(vP1_P2)
		)
	{
		//Findet eine Kollision Statt
		sf::Vector2f pushVector(vP1_P2_leftnorm);

		//Berrechne Länge des erwünschten vektors
		float magnitude = circle->getRadius() - projectedOnNormal;

		//Berrechne pushVektor
		pushVector.x = pushVector.x * magnitude;
		pushVector.y = pushVector.y * magnitude;

		//Wenn der auf vP1_P2_leftnorm projektierte vektor größer null ist
		//if (projectedOnNormal >= 0)		return -pushVector;
		//if (projectedOnNormal < 0)		return pushVector;

		return pushVector;
	}

	return sf::Vector2f(NULL, NULL);

}

sf::Vector2f PhysicsSystem::circlePolygonCollide(CircleBody* circle, PolygonBody* polygon)
{
	//Vektoren der Linien punkte
	sf::Vector2f p1;
	sf::Vector2f p2;

	//Vektor des Kreis mittlepunktes
	sf::Vector2f p3 = circle->getPos();

	//Die Punkte des Polygons.
	std::vector<sf::Vector2f> linePoints = polygon->getPoints();

	//Wenn es aus weniger als 2 punkten besteht, keine kollision / unmogliches Polygon
	if (linePoints.size() < 3)
	{
		std::cout << "Polygon mit weniger als 3 punkten" << std::endl;
		return sf::Vector2f(NULL, NULL);
	}

	///Kollision mit linien

	//Suche Punkt mit kleinster entfernung zu Kreis
	float smallestDistance = 1000000000;
	unsigned int smallestDistanceID;
	for (unsigned int i = 0; i < linePoints.size(); i++)
	{
		float squaredDist = Math::vectorSquaredDistance(linePoints[i], p3);
		if (squaredDist < smallestDistance)
		{
			smallestDistance = squaredDist;
			smallestDistanceID = i;
		}
	}

	//Tue diesen punkt und den vorerigen + kommenden in einen vektor
	std::vector<sf::Vector2f> threePointVector;
	threePointVector.push_back(linePoints[smallestDistanceID - 1]);
	threePointVector.push_back(linePoints[smallestDistanceID    ]);
	threePointVector.push_back(linePoints[smallestDistanceID + 1]);


	//Für jeden Punkt
	for (unsigned int i = 1; i <= 3; i++)
	{
		//P1 ist ein punkt der linie
		p1 = threePointVector[i - 1] + polygon->getPos();

		//P2 der andere
		p2 = threePointVector[i] + polygon->getPos();

		//Vektor von p1 nach p3;
		sf::Vector2f vP1_P3(p3.x - p1.x, p3.y - p1.y);
		//Vektor von P1 nach P2;
		sf::Vector2f vP1_P2(p2.x - p1.x, p2.y - p1.y);
		//Vektor vP1_P2 normalisiert
		sf::Vector2f vP1_P2_norm = Math::vectorNormalize(vP1_P2);
		//Vektor vP1_P2_norm um nach links gedreht ( 90° )
		sf::Vector2f vP1_P2_leftnorm(-vP1_P2_norm.y, vP1_P2_norm.x);

		//Länge des Vektors vP1_P2 auf vP1_P2_leftnorm projektiert
		float projectedOnNormal = Math::vectorProjectOn(vP1_P3, vP1_P2_leftnorm);
		//Länge des Vektors vP1_P2 auf vP1_P2_norm projektiert
		float projectedOnP1P2 = Math::vectorProjectOn(vP1_P3, vP1_P2_norm);

		if (
			//Wenn der auf vP1_P2_leftnorm projektierte vektor größer null ist
			projectedOnNormal >= 0 &&
			//Wenn der auf vP1_P2_leftnorm projektierte vektor kleiner ist als der Radius des Kreises
			std::fabs(projectedOnNormal) < circle->getRadius()
			//Und das Dot Produkt größer als null ist
			&& Math::vectorDot(vP1_P2, vP1_P3) > 0
			//Und der auf vP1_P2_norm projektierte vektor kleiner ist als die länge der Linie zwischen P1 und P2
			&& projectedOnP1P2 < Math::vectorLength(vP1_P2)
			)
		{
			//Findet eine Kollision Statt
			sf::Vector2f pushVector(vP1_P2_leftnorm);

			//Berrechne Länge des erwünschten vektors
			float magnitude = circle->getRadius() - projectedOnNormal;

			//Berrechne pushVektor
			pushVector.x = pushVector.x * magnitude;
			pushVector.y = pushVector.y * magnitude;

			return pushVector;
		}


	}

	///Kollision mit punkt
	p1 = linePoints[smallestDistanceID] + polygon->getPos();
	//Vektor von p1 nach p3;
	sf::Vector2f vP1_P3(p3.x - p1.x, p3.y - p1.y);
	if (Math::vectorLength(vP1_P3) < circle->getRadius())
	{		
		return Math::vectorSetMagnitude(vP1_P3, circle->getRadius() - Math::vectorLength(vP1_P3)+0.05f);
	}


	return sf::Vector2f(NULL, NULL);
}

sf::Vector2f PhysicsSystem::circleChainCollide(CircleBody* circle, ChainBody* chain)
{
	//Vektoren der Linien punkte
	sf::Vector2f p1;
	sf::Vector2f p2;

	//Vektor des Kreis mittlepunktes
	sf::Vector2f p3 = circle->getPos();

	//Die Punkte des Polygons.
	std::vector<sf::Vector2f> linePoints = chain->getPoints();

	//Wenn es aus weniger als 2 punkten besteht, keine kollision / unmogliches Polygon
	if (linePoints.size() < 3)
	{
		std::cout << "Chain mit weniger als 3 punkten" << std::endl;
		return sf::Vector2f(NULL, NULL);
	}

	///Kollision mit linien
	//Für jeden Punkt
	for (unsigned int i = 1; i <= linePoints.size(); i++)
	{


		//P1 ist ein punkt der linie
		p1 = linePoints[i - 1] + chain->getPos();

		//P2 der andere, wenn es der letzte punkt des polygons ist, nimmt es den ersten punkt
		if (i != linePoints.size())
		{
			p2 = linePoints[i] + chain->getPos();
		}
		else
		{
			p2 = linePoints[0] + chain->getPos();
		}

		//Vektor von p1 nach p3;
		sf::Vector2f vP1_P3(p3.x - p1.x, p3.y - p1.y);
		//Vektor von P1 nach P2;
		sf::Vector2f vP1_P2(p2.x - p1.x, p2.y - p1.y);
		//Vektor vP1_P2 normalisiert
		sf::Vector2f vP1_P2_norm = Math::vectorNormalize(vP1_P2);
		//Vektor vP1_P2_norm um nach links gedreht ( 90° )
		sf::Vector2f vP1_P2_leftnorm(-vP1_P2_norm.y, vP1_P2_norm.x);

		//Länge des Vektors vP1_P2 auf vP1_P2_leftnorm projektiert
		float projectedOnNormal = Math::vectorProjectOn(vP1_P3, vP1_P2_leftnorm);
		//Länge des Vektors vP1_P2 auf vP1_P2_norm projektiert
		float projectedOnP1P2 = Math::vectorProjectOn(vP1_P3, vP1_P2_norm);

		if (
			//Wenn der auf vP1_P2_leftnorm projektierte vektor größer null ist
			projectedOnNormal >= 0 &&
			//Wenn der auf vP1_P2_leftnorm projektierte vektor kleiner ist als der Radius des Kreises
			std::fabs(projectedOnNormal) < circle->getRadius()
			//Und das Dot Produkt größer als null ist
			&& Math::vectorDot(vP1_P2, vP1_P3) > 0
			//Und der auf vP1_P2_norm projektierte vektor kleiner ist als die länge der Linie zwischen P1 und P2
			&& projectedOnP1P2 < Math::vectorLength(vP1_P2)
			)
		{
			//Findet eine Kollision Statt
			sf::Vector2f pushVector(vP1_P2_leftnorm);

			//Berrechne Länge des erwünschten vektors
			float magnitude = circle->getRadius() - projectedOnNormal;

			//Berrechne pushVektor
			pushVector.x = pushVector.x * magnitude;
			pushVector.y = pushVector.y * magnitude;

			return pushVector;
		}


	}

	///Kollision mit punkten
	//Für alle punkte
	for (unsigned int i = 0; i < linePoints.size(); i++)
	{
		//p1
		p1 = linePoints[i] + chain->getPos();
		//Vektor von p1 nach p3;
		sf::Vector2f vP1_P3(p3.x - p1.x, p3.y - p1.y);

		if (Math::vectorLength(vP1_P3) < circle->getRadius())
		{
			return Math::vectorSetMagnitude(vP1_P3, circle->getRadius() - Math::vectorLength(vP1_P3) + 0.05f);
		}
	}

	return sf::Vector2f(NULL, NULL);

}

bool PhysicsSystem::LineIntersect(sf::Vector2f p0, sf::Vector2f p1, sf::Vector2f p2, sf::Vector2f p3)
{

	sf::Vector2f s1;
	sf::Vector2f s2;

	s1.x = p1.x - p0.x;
	s1.y = p1.y - p0.y;

	s2.x = p3.x - p2.x;
	s2.y = p3.y - p2.y;

	float s, t;
	s = (-s1.y * (p0.x - p2.x) + s1.x * (p0.y - p2.y)) / (-s2.x * s1.y + s1.x * s2.y);
	t = (s2.x * (p0.y - p2.y) - s2.y * (p0.x - p2.x)) / (-s2.x * s1.y + s1.x * s2.y);

	if (s >= 0 && s <= 1 && t >= 0 && t <= 1)
	{
		return true;
	}

	return false;
}

std::vector<Body*> PhysicsSystem::rayCast(sf::Vector2f pos, sf::Vector2f dir, bodyType bt, type wt)
{
	std::vector<Body*> b;
	sf::Vector2f direction(Math::vectorNormalize(dir));
	for (unsigned int i = 0; i < bodys.size(); i++)
	{
		if (bt == -1 || bodys[i]->getType() == bt)
		{
			if (wt== -1 || ( bodys[i]->getCollisionType() & wt ) > 0)
			{
				if (bodys[i]->rayCast(pos, direction))
				{
					b.push_back(bodys[i]);
				}
			}
		}

	}

	return b;
}