#ifndef ZOO_H
#define ZOO

#include <iostream>
#include <vector>

#include "Animal.h"

class Zoo{
    private:
    //std::vector<Animal> animals;
    //We will use a hashmap of animals
    //std::hashmap<>;
    public:
    Zoo();
    void addAnimal(Animal);
    Animal * getAnimalByID(int id);
};


#endif