#ifndef DOLPHIN_H
#define DOLPHIN_H

#include "AquaticAnimal.h"

class Dolphin: public AquaticAnimal{
    public:
    Dolphin(int id);
    bool timestep();
};

#endif