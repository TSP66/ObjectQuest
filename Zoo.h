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

struct EnclosureInformation{
    std::string name;
    EnclosureType type;
    float area;
    float volume;
    int cost;
};

struct AnimalInformation{
    std::string name; //of animal type
    Animals type;
    int cost;
    //Other stuff that we may need to create an Animal object
};

class Zoo{
    private:

    //Hashmap of Animals & Enclosures (maps id to pointer of object)
    std::unordered_map<int, std::shared_ptr<Animal>> animals;
    std::unordered_map<int, std::unique_ptr<Enclosure>> enclosures;

    //Vectors of Possible Animals & Enclosures to purchase
    std::vector<EnclosureInformation> enclosureInformation;
    std::vector<AnimalInformation> animalInformation;

    public:
    Zoo();
    void addAnimal(std::shared_ptr<Animal>);
    void addEnclosure(EnclosureType enclosureType);
    std::shared_ptr<Animal> getAnimalByID(int id);
    
    //Player actions
    bool buildEnclosure(void);

};

#endif