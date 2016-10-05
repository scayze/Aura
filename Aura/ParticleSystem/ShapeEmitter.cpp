#include "ShapeEmitter.h"

template<class T>
ShapeEmitter<T>::ShapeEmitter(sf::Vector2f pos) : ParticleEmitter(pos)
{

}

template<class T>
ShapeEmitter<T>::~ShapeEmitter()
{
	delete shape;
}

template<class T>
void ShapeEmitter<T>::tick()
{
	ParticleEmitter::tick();
}

template<class T>
void ShapeEmitter<T>::render(sf::RenderWindow * rW)
{
	//rW->draw(sprite);
	for (unsigned int i = 0; i < particles.size(); i++)
	{
		shape->setPosition(particles[i].position);
		rW->draw(*shape);
	}
}

template<class T>
void ShapeEmitter<T>::setShape(T * s)
{
	shape = s;
}

template class ShapeEmitter<sf::RectangleShape>;
template class ShapeEmitter<sf::CircleShape>;
template class ShapeEmitter<sf::ConvexShape>;