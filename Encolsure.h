#ifndef ENCOLSURE_H
#define ENCOLSURE_H

#include "Animal.h"
#include <unordered_map> 
#include <memory> 

class Encolsure{
    private:
    int maxAnimals;
    int id;
    //Hashmap to pointers to Animals
    std::unordered_map<int, std::shared_ptr<Animal>> animals;
    public:
    Encolsure(int, int);

};

#endif
