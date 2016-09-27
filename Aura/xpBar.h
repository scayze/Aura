#ifndef XpBar_H
#define XpBar_H

#include "window.h"
#include "Spieler.h"
#include <SFML\Graphics.hpp>

class XpBar : public Window
{
private:
	Spieler * player;
	sf::RectangleShape backGround;
	sf::RectangleShape diffBar;
	sf::RectangleShape xpBar;

	sf::Font textfont;
	sf::Text xp;

public:
	XpBar();
	void setPlayer(Spieler * s);
	void tick();
};

#endif