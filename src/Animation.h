#ifndef ANIMATION_H
#define ANIMATION_H

#include <SFML/Graphics.hpp>


class Animation
{
	private:

		sf::Sprite * sprite;

		float speed;
		int maxframe;
		int frameDelay;
		int frameHeight;
		int frameWidth;


		bool paused;
		float time;
		int frame;


	public:
		Animation();
		Animation(sf::Sprite * spr, int mf, int fh, int fw, int fd);
		void tick();

		void pause(bool p);
		void setMaxframe(int mf);
		void setFrame(int f);
		void setSpeed(float s);
		void setFrameDelay(int s);
		void changeSprite(sf::Sprite * spr);
		sf::Sprite * getSprite();
};

#endif