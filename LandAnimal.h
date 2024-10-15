#ifndef LANDANIMAL_H
#define LANDANIMAL_H

#include "Animal.h"

class LandAnimal: public Animal{
    public:
    LandAnimal(int id, std::string name, int);
    Death timestep();
};

//Macro to make creating lots of animals easy.
#define LAND_ANIMAL(NAME) \
    class NAME: public LandAnimal{ \
        public: \
        NAME(int id) : LandAnimal(id, #NAME, LIFESPAN_ANIMAL(NAME)) {} \
    };

//LANDANIMAL(Tiger).
//LANDANIMAL(Elephant).

#endif