#ifndef WORLDOBJECT_H
#define WORLDOBJECT_H

#include <SFML\Graphics.hpp>
#include "spielfeld.h"
#include "Physics/Bodys/CircleBody.h"
#include "Physics/Bodys/PolygonBody.h"
#include "math.h"
#include "RessourceManager\Resources.h"
#include "tweeny\tweeny.h"

enum type : unsigned char
{
	t_noCollide =	0b0000000,
	t_terrain =		0b0000001,
	t_spieler =		0b0000010,
	t_aura =		0b0000100,
	t_gegner =		0b0001000
};

class WorldObject
{
	protected:

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

		bool flag_destroy;
		bool flag_visible;
};

#endif