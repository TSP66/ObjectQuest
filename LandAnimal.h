#ifndef LANDANIMAL_H
#define LANDANIMAL_H

#include "Animal.h"

class LandAnimal: public Animal{
    private:
    float thirst;
    float minEnsolureSize;
    public:
    LandAnimal(int id, std::string name);
    virtual bool timestep();
};

#endif