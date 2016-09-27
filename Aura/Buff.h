#ifndef Buff_H
#define Buff_H

class WorldObject;

class Buff
{
protected:
	WorldObject * object;
	bool permanent;
	int duration;

public:
	Buff(WorldObject * obj);
	virtual void tick();
};

#endif