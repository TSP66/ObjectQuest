#ifndef TANK_H
#define TANK_H

#include "Encolsure.h"

class Tank: public Encolsure{
    private:
    float volume;
    public:
    Tank(float, int);
    int get_volume();
    void set_volume(int);
};

#endif