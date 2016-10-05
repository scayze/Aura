#ifndef TERRAIN_H
#define TERRAIN_H

#include "Worldobject.h"

class Terrain : public WorldObject
{
	private:

		sf::VertexArray vertexArray;
		sf::VertexArray vertexArrayOutline;
		bool drawn = false;

	public:
		Terrain(float x,float y);
		void init(Spielfeld * spiel);

		void render(sf::RenderWindow * rW);
		void tick();

		void updateVertexArray();



};


#endif