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

		std::bitset<8> collisionType = 0b0000000;
		std::bitset<8> collisionWith = 0b0000000;

		int mass;
		void * owner;

		AABB aabb;
		//sf::FloatRect aabb;



		sf::Vector2f pos;
		sf::Vector2f vel;
		
	public:
		Body();
		Body(float x, float y);

		virtual void tick();
		int getType();

		virtual bool testPoint(sf::Vector2f v) = 0;
		virtual bool rayCast(sf::Vector2f pos, sf::Vector2f dir) = 0;
		
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


		std::bitset<8> getCollisionType();
		void setCollisionType(std::bitset<8> byte);

		std::bitset<8> getCollisionWith();
		void setCollisionWith(std::bitset<8> byte);
		void addCollisionWith(std::bitset<8> byte);
};

#endif