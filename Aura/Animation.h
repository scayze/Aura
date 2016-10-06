#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML\Graphics.hpp>


class Animation
{
	private:
		sf::Sprite * sprite;
		int frame;
		int maxframe;
		float speed;
		float maxspeed;
		float time;
		int dir;



	public:
		Animation();
		Animation(sf::Sprite * spr, int mf, float spd);
		void animieren(int o, int w, int h);
		void tick();
};

#endif