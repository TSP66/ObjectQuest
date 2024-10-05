#ifndef ENCOLSURE_H
#define ENCOLSURE_H

#include "Animal.h"
#include <unordered_map> 
#include <memory> 

class Enclosure{
    private:
    int maxAnimals;
    int id;
    //Hashmap to pointers to Animals
    std::unordered_map<int, std::shared_ptr<Animal>> animals;
    public:
    Enclosure(int);
    int get_id(void);
    void set_id(int);
};

#endif
