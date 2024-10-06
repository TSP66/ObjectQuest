#ifndef AQUATICANIMAL_H
#define AQUATICANIMAL_H

#include "Animal.h"

class AquaticAnimal: public Animal{
    private:
    float volumeRequired;
    public:
    AquaticAnimal(int id, std::string name);
    virtual bool timestep();

};

#endif