#include "window.h"

Window::Window()
{

}

void Window::tick()
{

}

void Window::render(sf::RenderTexture * t)
{
	for (unsigned int i = 0; i < drawables.size(); i++)
	{
		t->draw(*drawables[i]);
	}
}