#ifndef HealthBar_H
#define HealthBar_H

#include "window.h"
#include "../../Spieler.h"
#include <SFML/Graphics.hpp>

class HealthBar : public Window
{
private:
	Spieler * player;
	sf::RectangleShape backGround;
	sf::RectangleShape diffBar;
	sf::RectangleShape redBar;

	sf::Text hp;

public:
	HealthBar();
	void setPlayer(Spieler * s);
	void tick();
};

#endif
