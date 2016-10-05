#include "Terrain.h"
#include <iostream>

Terrain::Terrain(float x, float y) : WorldObject(x,y)
{

	//Change Body type to a Chain
	delete body; 
	body = new ChainBody();
	body->setPos(x, y);
	body->setCollisionType(t_terrain);
	body->setMass(10);

	vertexArray.setPrimitiveType(sf::TrianglesFan);
	vertexArrayOutline.setPrimitiveType(sf::LinesStrip);
	//Non movable
	body->isStatic = true;

}

void Terrain::render(sf::RenderWindow * rW)
{
	//Draw only once to background texture of spielfeld
	if (!drawn)
	{
		spielfeld->getBackgroundTexture()->draw(vertexArray);
		spielfeld->getBackgroundTexture()->draw(vertexArrayOutline);

		drawn = true;
		spielfeld->updateBackground();
	}
}

void Terrain::tick()
{
	WorldObject::tick();
	if (body->getPos() != sf::Vector2f(vertexArray[0].position.x, vertexArray[0].position.y)) updateVertexArray();
}

void Terrain::init(Spielfeld * spiel)
{

	WorldObject::init(spiel);
}

void Terrain::updateVertexArray()
{
	vertexArray.clear();
	vertexArrayOutline.clear();
	vertexArray.append(body->getPos());
	vertexArray[0].color = sf::Color(80, 80, 80);

	std::vector<sf::Vector2f> vector = static_cast<PolygonBody*>(body)->getPoints();
	for (unsigned int i = 0; i < vector.size(); i++)
	{
		vertexArray.append(vector[i] + body->getPos());
		vertexArrayOutline.append(vector[i] + body->getPos());

		vertexArray[i+1].color = sf::Color(80, 80, 80);
		vertexArrayOutline[i].color = sf::Color(200, 200, 200);
	}

	vertexArray.append(vertexArray[1]);
	vertexArrayOutline.append(vertexArray[1]);
	vertexArrayOutline[vertexArrayOutline.getVertexCount()-1].color = sf::Color(200, 200, 200);
}