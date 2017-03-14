#ifndef STEUERUNG_H
#define STEUERUNG_H

#include <SFML/Graphics.hpp>
#include "spielfeld.h"

class Steuerung
{
	private:
		sf::RenderWindow rWindow;
		sf::ContextSettings settings;

		Spielfeld* spielfeld;

		double deltaTime;
		double time;

		sf::Clock clock;
		sf::Clock FPS;
		int fpscount;
		int tickcount;


	public:

		Steuerung();
		void run();
		void tick();
		void render();

};

#endif