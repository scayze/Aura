#include "Animation.h"
#include <iostream>

Animation::Animation()
{

}

Animation::Animation(sf::Sprite * spr, int mf = 1, int fw = 10, int fh = 10, int fd = 10)
{
	paused = false;
	sprite = spr;
	maxframe = mf;
	frameDelay = fd;
	frame = 0;
	frameHeight = fh;
	frameWidth = fw;
	speed = 1.f;
	
	sprite->setTextureRect(sf::IntRect(frame*frameWidth,0,frameWidth,frameHeight));
}

void Animation::tick()
{
	//Return if the thingy is actually paused
	if(paused) return;

	time += 1*speed;
	//Return if next frame hasnt been reached
	if(time < frameDelay) return;
	time = 0;
	//Increment frame and reset to zero if it exceeds maxframe
	++frame;
	if(frame>=maxframe) frame = 0;
	//Update the texture rect accordingly
	sprite->setTextureRect(sf::IntRect(frame*frameWidth,0,frameWidth,frameHeight));
}

void Animation::changeSprite(sf::Sprite * s)
{
	sprite = s;
	sprite->setTextureRect(sf::IntRect(frame*frameWidth,0,frameWidth,frameHeight));
}

void Animation::setFrameDelay(int fd)
{
	frameDelay = fd;
}

void Animation::pause(bool p)
{
	paused = p;
}

void Animation::setMaxframe(int mf)
{
	maxframe = mf;
}

void Animation::setSpeed(float s)
{
	speed = s;
}

void Animation::setFrame(int f)
{
	frame = f;
}

sf::Sprite * Animation::getSprite()
{
	return sprite;
}