#ifndef RessourceManager_H
#define RessourceManager_H

#include "Managers\TextureManager.h"
#include "Managers\FontManager.h"

class RessourceManager
{
private:


public:

	static const sf::Image& getTexture(std::string path);
	static const sf::Font& getFont(std::string path);
};

#endif
