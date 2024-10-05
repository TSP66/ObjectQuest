#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <unordered_map> 
#include <memory>
#include <random>  

#include "Animal.h"
#include "Enclosure.h"
#include "LandEnclosure.h"
#include "Tank.h"

enum EnclosureType{
    LAND,
    AQUATIC,
};

enum Animals{
    LION,
    DOLPHIN,
};

class Zoo{
    private:
    //Hashmap of Animals
    std::unordered_map<int, std::shared_ptr<Animal>> animals;
    std::unordered_map<int, std::unique_ptr<Enclosure>> enclosures;
    public:
    Zoo();
    void addAnimal(std::shared_ptr<Animal>);
    void addEnclosure(EnclosureType enclosureType);
    std::shared_ptr<Animal> getAnimalByID(int id);
    
    //Player actions
    bool buildEnclosure(void);

};

#endif