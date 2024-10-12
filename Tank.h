#ifndef TANK_H
#define TANK_H

#include "Enclosure.h"

class Tank: public Enclosure{
    public:
    Tank();
    Tank(std::string, int);
};

#endif