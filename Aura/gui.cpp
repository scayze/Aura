#include "gui.h"

GUI_System::GUI_System()
{
	guiTexture.create(1000, 800);
	//guiTexture.getTexture().
}

void GUI_System::addWindow(Window* w)
{
	windows.push_back(w);
}

void GUI_System::tick()
{
	for (unsigned int i = 0; i < windows.size(); i++)
	{
		windows[i]->tick();
	}
}

void GUI_System::render(sf::RenderWindow * rW)
{
	guiTexture.clear(sf::Color::Transparent);

	for (unsigned int i = 0; i < windows.size(); i++)
	{
		windows[i]->render(&guiTexture);
	}

	guiTexture.display();

	rW->draw(sf::Sprite(guiTexture.getTexture()));
}
