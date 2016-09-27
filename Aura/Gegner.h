#ifndef Gegner_H
#define Gegner_H

#include "Figur.h"

class Gegner : public Figur
{
    protected:



    public:
        Gegner(float x, float y);
        virtual void tick();
		virtual void init(Spielfeld * spielfeld);
};

#endif