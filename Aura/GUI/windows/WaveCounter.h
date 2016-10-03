#ifndef WaveCounter_H
#define WaveCounter_H

#include "window.h"
#include <SFML\Graphics.hpp>

class WaveCounter : public Window
{
private:
	int * count;
	sf::RectangleShape backGround;
	sf::Text counter;

public:
	WaveCounter();
	void setCounter(int &counter);
	void tick();
};

#endif