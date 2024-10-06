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


#define AQUATIC_ANIMAL(NAME) \
    class NAME: public AquaticAnimal{ \
        public: \
        NAME(int id) : AquaticAnimal(id, #NAME) {} \
        bool timestep() {return true;} \
    };

#endif