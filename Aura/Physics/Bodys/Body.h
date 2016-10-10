#ifndef BODY_H
#define BODY_H

#include <SFML\Graphics.hpp>
#include "../../math.h"
#include <bitset>

enum bodyType
{
	Circle = 0,
	Polygon = 1,
	Edge = 2,
	Chain = 3
};

struct AABB
{
	float left;
	float top;
	float width;
	float height;

	bool intersects(AABB& aabb)
	{
		bool result = true;

		result = result && left < aabb.left + aabb.width;
		result = result && left + width > aabb.left;
		result = result && top < aabb.top + aabb.height;
		result = result && height + top > aabb.top;

		return result;
	}
};

class Body
{
	protected:

		int bodyType;

		unsigned char collisionType = 0b0000000;
		unsigned char collisionWith = 0b0000000;

		int mass;
		void * owner;

		AABB aabb;

		sf::Vector2f pos;
		sf::Vector2f vel;
		
	public:
		Body();
		Body(float x, float y);

		virtual void tick();
		int getType();

		virtual bool testPoint(sf::Vector2f v) = 0;
		virtual float rayCast(sf::Vector2f pos, sf::Vector2f dir) = 0;
		
		virtual void updateAABB() = 0;
		AABB& getAABB();

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


		unsigned char getCollisionType();
		void setCollisionType(unsigned char byte);

		unsigned char getCollisionWith();
		void setCollisionWith(unsigned char byte);
		void addCollisionWith(unsigned char byte);
};

#endif