#include "HealthBar.h"
#include <string>

HealthBar::HealthBar()
{
	backGround.setPosition(5, 5);
	backGround.setSize(sf::Vector2f(600, 30));
	backGround.setFillColor(sf::Color(20, 20, 20, 150));
	backGround.setOutlineColor(sf::Color(0, 0, 0, 200));
	backGround.setOutlineThickness(1.5);
	
	redBar.setPosition(6.5, 6.5);
	redBar.setFillColor(sf::Color(200, 20, 20));

	diffBar.setPosition(6.5, 6.5);
	diffBar.setSize(sf::Vector2f(backGround.getSize().x, 0));
	diffBar.setFillColor(sf::Color(100, 20, 20));

	//hp.setCharacterSize(20);
	hp.setFont(RessourceManager::getFont("Ressources/fonts/emulogic.ttf"));
	hp.setCharacterSize(16);
	hp.setColor(sf::Color(5, 80, 5));
	hp.setPosition(backGround.getSize().x / 2, backGround.getSize().y / 2 + 2);
	hp.setString("");

	drawables.push_back(&backGround);
	drawables.push_back(&diffBar);
	drawables.push_back(&redBar);
	drawables.push_back(&hp);
}

void HealthBar::setPlayer(Spieler * s)
{
	player = s;
}

void HealthBar::tick()
{
	if (redBar.getSize().x < diffBar.getSize().x) diffBar.setSize(sf::Vector2f(diffBar.getSize().x-2, redBar.getSize().y));

	redBar.setSize(sf::Vector2f(backGround.getSize().x * (float)player->getHealthPoints() / (float)player->getMaxHealth() - 3, 27));


	hp.setString(std::to_string(player->getHealthPoints()) + "/" + std::to_string(player->getMaxHealth()));
	hp.setOrigin(hp.getLocalBounds().width / 2, hp.getLocalBounds().height / 2);

	if (player->getHealthPoints() > player->getMaxHealth() / 2) hp.setColor(sf::Color(5, 200, 5));
	else if (player->getHealthPoints() < player->getMaxHealth() / 4) hp.setColor(sf::Color(200, 5, 5));
	else hp.setColor(sf::Color(255, 150, 5));
}