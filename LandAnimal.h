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

//Macro to make creating lots of animals easy
#define LAND_ANIMAL(NAME) \
    class NAME: public LandAnimal{ \
        public: \
        NAME(int id) : LandAnimal(id, #NAME) {} \
        bool timestep(){return true;} \
    };

//LANDANIMAL(Tiger)
//LANDANIMAL(Elephant)

#endif