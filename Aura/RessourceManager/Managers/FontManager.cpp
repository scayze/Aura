#include "FontManager.h"
#include <iostream>


fRessource& FontManager::load(std::string dPath)
{
	fRessource * res = new fRessource;
	res->font.loadFromFile(dPath);
	res->path = dPath;

	data.push_front(res);

	return *res;
}


bool FontManager::unload(std::string dPath)
{


	std::list<fRessource*>::iterator it = data.begin();
	for (it = data.begin(); it != data.end(); it++)
	{
		if ((*it)->path == dPath)
		{
			delete (*it);
			data.erase(it);
		}
	}

	return true;
}


const sf::Font& FontManager::get(std::string dPath)
{
	std::list<fRessource*>::iterator it = data.begin();
	for (it = data.begin(); it != data.end(); it++)
	{
		if ((*it)->path == dPath)
		{
			//std::cout << dPath + " load from memory" << std::endl;
			return (*it)->font;
		}
	}
	std::cout << dPath + " load from file" << std::endl;
	return load(dPath).font;
}
