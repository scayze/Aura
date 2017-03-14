#include "DDraw.h"

std::vector<sf::Drawable *> drawables;

void DDraw::draw(sf::RenderWindow *rW)
{
	for(unsigned int i = 0; i < drawables.size(); i++)
	{
		rW->draw(*drawables[i]);
		//delete drawables[i];
	}
	
	drawables.clear();
}

void DDraw::add(sf::Drawable *rW)
{
	drawables.push_back(rW);
}