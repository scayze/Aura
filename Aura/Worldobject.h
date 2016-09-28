#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <SFML\Graphics.hpp>
#include "spielfeld.h"
#include "Physics/Bodys/CircleBody.h"
#include "Physics/Bodys/PolygonBody.h"
#include "math.h"
#include "RessourceManager\RessourceManager.h"
#include "tweeny\tweeny.h"

enum type
{

	t_terrain = 0,
	t_spieler = 1,
	t_aura = 2,
	t_gegner = 3,
	t_noCollide = 4,
	t_playerOnly = 5
};

class WorldObject
{
	protected:

		int type;

		Spielfeld * spielfeld;

		sf::Texture texture;
		sf::Sprite sprite;

		Body * body;




	public:
		WorldObject(float x, float y);
		virtual ~WorldObject();
		virtual void init(Spielfeld * spiel);
		virtual void tick();

		virtual void render(sf::RenderWindow * rW);
		virtual void collide(WorldObject * object);

		sf::Sprite& getSprite();
		Body * getBody();
		int getType();

		bool flag_destroy;
		bool flag_visible;
};

#endif