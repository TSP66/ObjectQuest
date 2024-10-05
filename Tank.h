#ifndef TANK_H
#define TANK_H

#include "Enclosure.h"

class Tank: public Enclosure{
    private:
    float volume;
    public:
    Tank();
    Tank(float, int);
    int get_volume();
    void set_volume(int);
};

#endif