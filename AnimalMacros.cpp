#include "AnimalMacros.h"

Animals mapStringToAnimal(std::string animal){
    #define XX(NAME) if(animal == #NAME){ \
                return CAPITALIZE_ANIMAL(NAME); \
            }
    ANIMAL_LIST(XX)
    #undef X
    return (Animals) 0;
}

int animalToPrice(Animals animal){
    switch (animal){
        #define XX(NAME) case NAME: \
            return PRICE_ANIMAL(NAME);
        #undef XX
    }
}