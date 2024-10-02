#ifndef LION_H
#define LION_H

#include "LandAnimal.h"

class Lion: public LandAnimal{
    public:
    Lion(int);
    bool timestep();
    
};

#endif