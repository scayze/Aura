#include "RessourceManager.h"
#include "iostream"

TextureManager tManager;
FontManager fManager;

void RessourceManager::loadTexture(sf::Texture& tex, std::string path)
{
	tex.loadFromImage(tManager.get("Ressources/Graphics/" + path));
}

const sf::Image& RessourceManager::getTexture(std::string path)
{
	return tManager.get(path);
}

const sf::Font& RessourceManager::getFont(std::string path)
{
	return fManager.get(path);
}