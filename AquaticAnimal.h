#ifndef AQUATICANIMAL_H
#define AQUATICANIMAL_H

#include "Animal.h"

class AquaticAnimal: public Animal{
    private:
    float volumeRequired;
    public:
    AquaticAnimal(int id);
    virtual bool timestep();

};

#endif