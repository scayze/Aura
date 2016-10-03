#ifndef SPIELFELD_H
#define SPIELFELD_H


#include <SFML\Graphics.hpp>
#include "Physics/PhysicsSystem.h"
#include "GUI/gui.h"

class WorldObject;
class Spieler;


class Spielfeld
{
	private:
		float width;
		float height;
		int counter;

		Spieler * player;

		PhysicsSystem pSystem;
		GUI_System guiSystem;

		std::vector<WorldObject*> objects;

		sf::RenderTexture backgound;

		sf::RenderWindow* rWindow;

	public:
		Spielfeld(sf::RenderWindow* window);

		void tick();
		void render();
		Spieler * getPlayer();
		PhysicsSystem * getPhysicsSystem();
		sf::RenderTexture * getBackgroundTexture();
		void updateBackground();

		template<typename T>
		T* createObject(float x, float y)
		{
			T* obj = new T(x,y);
			obj->init(this);
			pSystem.addBody(obj->getBody());
			objects.push_back(obj);
			return obj;
		};

};

#endif