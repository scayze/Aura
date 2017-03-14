#ifndef GUI_System_H
#define GUI_System_H

#include <SFML/Graphics.hpp>
#include "windows/window.h"

class GUI_System
{

private:
	std::vector<Window*> windows;
	sf::RenderTexture guiTexture;

public:

	GUI_System();
	void tick();
	void render(sf::RenderWindow * rW);
	void addWindow(Window * b);

};

#endif
