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
#include "EnclosureInformation.h"
#include "AnimalInformation.h"

#define INDENT "    "

class Zoo{

    private:

    //Hashmap of Animals & Enclosures (maps id to pointer of object)
    std::vector<int> animalIds;
    std::vector<int> enclosureIds;

    std::unordered_map<int, std::shared_ptr<Animal>> animals;
    std::unordered_map<int, std::unique_ptr<Enclosure>> enclosures;


    //Actions to build starting infromation - should be private
    std::vector<EnclosureInformation> makeEnclosureInformation();
    std::vector<AnimalInformation> makeAnimalInformation();

    public:

    //Vectors of Possible Animals & Enclosures to purchase - should be private
    std::vector<EnclosureInformation> enclosureInformation;
    std::vector<AnimalInformation> animalInformation;

    Zoo();

    void addAnimal(std::shared_ptr<Animal>);
    void addEnclosure(EnclosureInformation enclosureType);

    std::shared_ptr<Animal> getAnimalByID(int id);


    //Player actions
    int buildEnclosure(void);
    int buyAnimal();
    template <typename T> int displayOptions(std::vector<T>);

};
#endif