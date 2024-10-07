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
    bool addAnimal(int, std::shared_ptr<Animal>);
    bool removeAnimal(int);
    int get_id(void);
    void set_id(int);
    std::string get_name(void);
};

#endif
