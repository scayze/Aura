#include "Terrain.h"
#include <iostream>

Terrain::Terrain(float x, float y) : WorldObject(x,y)
{
	type = t_terrain;

	delete body; 
	body = new ChainBody();
	body->setPos(x, y);

	body->setMass(10);
	body->isStatic = true;

	//updateVertexArray();


}

void Terrain::render(sf::RenderWindow * rW)
{
	for (unsigned int i = 0; i < vertexArray.getVertexCount(); i++)
	{
		vertexArray[i].color = sf::Color(80,80,80);
	}
	vertexArray.setPrimitiveType(sf::TrianglesFan);

	rW->draw(vertexArray);

	for (unsigned int i = 0; i < vertexArray.getVertexCount(); i++)
	{
		vertexArray[i].color = sf::Color(200,200,200);
	}
	vertexArray.setPrimitiveType(sf::LinesStrip);
	rW->draw(vertexArray);
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
	vertexArray.append(body->getPos());

	std::vector<sf::Vector2f> vector = static_cast<PolygonBody*>(body)->getPoints();
	for (unsigned int i = 0; i < vector.size(); i++)
	{
		vertexArray.append(vector[i] + body->getPos());
	}

	vertexArray.append(vertexArray[1]);
}