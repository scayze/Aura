#include "Animation.h"
#include <iostream>

Animation::Animation()
{

}

Animation::Animation(sf::Sprite * spr, int mf, float spd)
{
	sprite = spr;
	maxframe = mf;
	speed = spd;
	maxspeed = speed;
	frame = 0;
	dir = 1;
}

void Animation :: animieren(int o, int w, int h)
{
	sprite->setTextureRect(sf::IntRect(frame*w,o,w,h));
	speed--;
	if (speed == 0)
	{
		if (dir == 1)
		{
			frame++;
			speed = maxspeed;
			if (frame > maxframe)
			{
				frame = maxframe;
				dir = 0;
			}
		}
		if (dir == 0)
		{
			frame--;
			speed = maxspeed;
			if (frame <= 0)
			{
				frame = 0;
				dir = 1;
			}
		}
	}
}

void Animation :: tick()
{

}