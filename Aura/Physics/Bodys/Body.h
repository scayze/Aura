#ifndef BODY_H
#define BODY_H

#include <SFML\Graphics.hpp>

enum bodyType
{
	Circle = 0,
	Polygon = 1,
	Edge = 2,
	Chain = 3
};

struct AABB
{
	sf::Vector2f center;
	sf::Vector2f topLeft;
	sf::Vector2f downRight;
};

class Body
{
	protected:

		int type;

		int mass;
		void * owner;

		AABB aabb;
		sf::FloatRect AABB;



		sf::Vector2f pos;
		sf::Vector2f vel;
		
	public:
		Body();
		Body(float x, float y);

		virtual void tick();
		int getType();

		virtual bool testPoint(sf::Vector2f v) = 0;
		
		virtual void updateAABB() = 0;
		sf::FloatRect getAABB();

		virtual void debugDraw(sf::RenderWindow * rW);

		int getMass();
		void setMass(int m);

		sf::Vector2f getPos();
		void setPos(float x, float y);
		void setPos(sf::Vector2f vec);

		sf::Vector2f getVel();
		void setVel(float x, float y);
		void setVel(sf::Vector2f vec);

		bool flagDestroy = false;
		bool isStatic;

		void * getOwner();
		void setOwner(void * o);
};

#endif