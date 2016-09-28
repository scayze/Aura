#include "TextureManager.h"
#include <iostream>


tRessource& TextureManager::load(std::string dPath)
{
	tRessource * res = new tRessource;
	res->img.loadFromFile(dPath);
	res->path = dPath;

	data.push_front(res);

	return *res;
}


bool TextureManager::unload(std::string dPath)
{


	std::list<tRessource*>::iterator it = data.begin();
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


const sf::Image& TextureManager::get(std::string dPath)
{
	std::list<tRessource*>::iterator it = data.begin();
	for (it = data.begin(); it != data.end(); it++)
	{
		if ((*it)->path == dPath)
		{
			//std::cout << dPath + " load from memory" << std::endl;
			return (*it)->img;
		}
	}
	std::cout << dPath + " load from file" << std::endl;
	return load(dPath).img;
}
