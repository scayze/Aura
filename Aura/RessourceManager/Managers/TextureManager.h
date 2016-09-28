#ifndef TextureManager_h
#define TextureManager_h

#include <SFML/Graphics.hpp>
#include <list>

struct tRessource
{
	sf::Image img;
	std::string path;
};


class TextureManager
{
private:

	std::list<tRessource*> data;

	tRessource& load(std::string dPath);
	bool unload(std::string dPath);

public:
	const sf::Image& get(std::string dPath);
};



#endif