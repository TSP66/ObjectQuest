#ifndef BREEDANIMAL.H
#define BREEDANIMAL.H
#include "Animal.h"



class BreedAnimal {
    private : 
    public :
        BreedAnimal();
        BreedAnimal(Animal animal1, Animal animal2);
        int checkBreedTimer();
};

#endif