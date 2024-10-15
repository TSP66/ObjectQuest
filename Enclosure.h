#ifndef ENCOLSURE_H
#define ENCOLSURE_H

#include "Animal.h"
#include "EnclosureInformation.h"
#include <unordered_map> 
#include <memory> 
#include <string>
#include <vector>

class Enclosure{
    private:
    int maxAnimals;
    int id;
    int currentAnimals;
    //Hashmap to pointers to Animals
    std::string name;
    public:
    std::unordered_map<int, std::shared_ptr<Animal>> animals;
    EnclosureType enclosureType;
    Enclosure(std::string, int, EnclosureType);
    bool addAnimal(int, std::shared_ptr<Animal>); //adds animal
    bool removeAnimal(int); //removes animal
    int get_id(void); //returns ID of individual animal
    void set_id(int); //sets the animal ID to a specific used ID
    int get_currentAnimals(void); //Returns current animals in enclosure 
    int get_maxAnimals(void); //returns max amout of animals that can fit in enclosure 
    std::string get_name(void); //returns name of enclosure 
};

#endif
