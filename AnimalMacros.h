#ifndef ANIMAL_MACROS_H
#define ANIMAL_MACROS_H

#include <iostream>
#include <string>

#include "AquaticAnimal.h"
#include "LandAnimal.h"

//To add an another animal modify this section

#define LAND_ANIMAL_LIST(XX) \
    XX(Lion) \
    XX(Tiger) 

#define AQUATIC_ANIMAL_LIST(XX) \
    XX(Dolphin) \
    XX(Otter) \
    XX(Fish)

#define CAPITALIZE_Otter OTTER
#define CAPITALIZE_Lion LION
#define CAPITALIZE_Tiger TIGER
#define CAPITALIZE_Dolphin DOLPHIN
#define CAPITALIZE_Fish FISH

#define PRICE_Lion 30
#define PRICE_Tiger 50
#define PRICE_Dolphin 20
#define PRICE_Otter 20
#define PRICE_Fish 10

#define LIFESPAN_Lion 10.0
#define LIFESPAN_Tiger 5.0
#define LIFESPAN_Dolphin 7.0
#define LIFESPAN_Otter 2.0
#define LIFESPAN_Fish 1.0

//------------------------------------------

#define CAPITALIZE_ANIMAL(animal) CAPITALIZE_##animal
#define PRICE_ANIMAL(animal) PRICE_##animal
#define LIFESPAN_ANIMAL(animal) LIFESPAN_##animal

#define XX(NAME) LAND_ANIMAL(NAME) 
LAND_ANIMAL_LIST(XX)
#undef XX

#define XX(NAME) AQUATIC_ANIMAL(NAME) 
AQUATIC_ANIMAL_LIST(XX)
#undef XX

#define ANIMAL_LIST(XX) \
    LAND_ANIMAL_LIST(XX) \
    AQUATIC_ANIMAL_LIST(XX) \

enum Animals{
    #define XX(NAME) CAPITALIZE_ANIMAL(NAME),
    ANIMAL_LIST(XX)
    #undef XX
};

Animals mapStringToAnimal(std::string animal);

int animalToPrice(Animals animal);

#endif