#include "Steuerung.h"
#include <iostream>
#include "tweeny\tweeny.h"

Steuerung::Steuerung()
{

	deltaTime = 1.0 / 60.0;
	time = 0;


	settings.antialiasingLevel = 8;

	rWindow.create(sf::VideoMode(1000,800),"Paulaner Spezi",sf::Style::Default, settings);


	rWindow.setVerticalSyncEnabled(true);

	spielfeld = new Spielfeld(&rWindow);


}

void Steuerung::run()
{
	while(rWindow.isOpen())
	{
		sf::Event event;
		while(rWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				rWindow.close();
			}
		}

		//Semi Fixed Timestep
		time += clock.restart().asSeconds();
		while(time >= deltaTime)
		{
			tick();
			time-=deltaTime;
			tickcount++;
		}

		fpscount++;
		render();

		if(FPS.getElapsedTime().asSeconds()>1)
		{
			FPS.restart();

			std::cout << "FPS: " << fpscount << std::endl;
			std::cout << "Ticks: " << tickcount << std::endl;

			fpscount=0;
			tickcount = 0;
		}
	}
}

void Steuerung::tick()
{
	spielfeld->tick();
}

void Steuerung::render()
{
	
	rWindow.clear();

	spielfeld->render();

	rWindow.display();
}