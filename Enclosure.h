#ifndef ENCOLSURE_H
#define ENCOLSURE_H

#include "Animal.h"
#include <unordered_map> 
#include <memory> 
#include <string>

class Enclosure{
    private:
    int maxAnimals;
    int id;
    int currentAnimals;
    //Hashmap to pointers to Animals
    std::string name;
    std::unordered_map<int, std::shared_ptr<Animal>> animals;
    public:
    Enclosure(std::string, int);
    int get_id(void);
    void set_id(int);
    std::string get_name(void);
};

#endif
