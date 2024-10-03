#ifndef ZOO_H
#define ZOO

#include <iostream>
#include <unordered_map> 
#include <memory> 

#include "Animal.h"

class Zoo{
    private:
    //Hashmap of Animals
    std::unordered_map<int, std::shared_ptr<Animal>> animals;
    public:
    Zoo();
    void addAnimal(std::shared_ptr<Animal>);
    std::shared_ptr<Animal> getAnimalByID(int id);
};


#endif