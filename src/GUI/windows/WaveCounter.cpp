#include "WaveCounter.h"
#include <string>
#include <iostream>

WaveCounter::WaveCounter()
{
	backGround.setPosition(500, 770);
	backGround.setSize(sf::Vector2f(100, 30));
	backGround.setOrigin(backGround.getLocalBounds().width / 2, backGround.getLocalBounds().height / 2);
	backGround.setFillColor(sf::Color(20, 20, 20, 150));
	backGround.setOutlineColor(sf::Color(0, 0, 0, 200));
	backGround.setOutlineThickness(2);

	//hp.setCharacterSize(20);
	counter.setFont(Resources::getFont("emulogic.ttf"));
	counter.setCharacterSize(16);
	counter.setFillColor(sf::Color(5, 80, 5));
	//counter.setOrigin(backGround.getSize().x / 2, backGround.getSize().x / 2);
	counter.setPosition(backGround.getPosition().x,backGround.getPosition().y);
	counter.setString("00:00");
	counter.setOrigin(counter.getLocalBounds().width / 2, counter.getLocalBounds().height / 2);

	drawables.push_back(&backGround);
	drawables.push_back(&counter);
}

void WaveCounter::setCounter(int &c)
{
	count = &c;
}

void WaveCounter::tick()
{
	counter.setString(std::to_string(*count/60) + ":" + std::to_string((int)(*count%60 * (10.f/6.f)) ));

	if (*count > 10*60)		counter.setFillColor(sf::Color(5, 200, 5));
	else if (*count < 5*60) counter.setFillColor(sf::Color(200, 5, 5));
	else					counter.setFillColor(sf::Color(255, 150, 5));
}
