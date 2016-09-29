#include "XpBar.h"
#include <string>

XpBar::XpBar()
{
	backGround.setPosition(5, 38);
	backGround.setSize(sf::Vector2f(600, 10));
	backGround.setFillColor(sf::Color(20, 20, 20, 150));
	backGround.setOutlineColor(sf::Color(0, 0, 0, 200));
	backGround.setOutlineThickness(1);

	xpBar.setPosition(6, 39);
	xpBar.setFillColor(sf::Color(20, 20, 100));

	diffBar.setPosition(6, 39);
	diffBar.setSize(sf::Vector2f(backGround.getSize().x, 0));
	diffBar.setFillColor(sf::Color(20, 20, 200));

	//textfont.lo(RessourceManager::getTexture("Ressources/fonts/emulogic.ttf");

	//hp.setCharacterSize(20);
	xp.setFont(Resources::getFont("Ressources/fonts/emulogic.ttf"));
	xp.setCharacterSize(9);
	xp.setColor(sf::Color(5, 5, 250));
	xp.setPosition(backGround.getPosition().x + backGround.getSize().x / 2, backGround.getPosition().y + backGround.getSize().y / 2 - 1);
	xp.setString("");

	drawables.push_back(&backGround);
	drawables.push_back(&xpBar);
	drawables.push_back(&diffBar);
	drawables.push_back(&xp);
}

void XpBar::setPlayer(Spieler * s)
{
	player = s;
}

void XpBar::tick()
{
	if (xpBar.getSize().x > diffBar.getSize().x) diffBar.setSize(sf::Vector2f(diffBar.getSize().x + 2, xpBar.getSize().y));

	if (xpBar.getSize().x < diffBar.getSize().x) diffBar.setSize(xpBar.getSize());

	xpBar.setSize(sf::Vector2f(backGround.getSize().x * (float)player->getXP() / (float)player->getXpNeeded(), 8));


	xp.setString(std::to_string(player->getXP()) + "/" + std::to_string(player->getXpNeeded()));
	xp.setOrigin(xp.getLocalBounds().width / 2, xp.getLocalBounds().height / 2);
}