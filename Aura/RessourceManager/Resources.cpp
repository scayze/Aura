#include "Resources.h"
#include "iostream"

TextureManager tManager;
FontManager fManager;

void Resources::loadTexture(sf::Texture& tex, std::string path)
{
	tex.loadFromImage(tManager.get("Ressources/Graphics/" + path));
}

const sf::Image& Resources::getTexture(std::string path)
{
	return tManager.get(path);
}

const sf::Font& Resources::getFont(std::string path)
{
	return fManager.get(path);
}