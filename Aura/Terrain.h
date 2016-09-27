#ifndef TERRAIN_H
#define TERRAIN_H

#include "Worldobject.h"

class Terrain : public WorldObject
{
	private:

		sf::VertexArray vertexArray;

	public:
		Terrain(float x,float y);
		void init(Spielfeld * spiel);

		void render(sf::RenderWindow * rW);
		void tick();

		void updateVertexArray();



};


#endif