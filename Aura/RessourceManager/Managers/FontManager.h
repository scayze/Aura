#ifndef FontManager_h
#define FontManager_h

#include <SFML/Graphics.hpp>
#include <list>


struct fRessource
{
	sf::Font font;
	std::string path;
};

class FontManager
{


private:

	std::list<fRessource*> data;

	fRessource& load(std::string dPath);
	bool unload(std::string dPath);

public:
	const sf::Font& get(std::string dPath);
};



#endif