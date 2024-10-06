#include "Enclosure.h"


Enclosure::Enclosure(std::string name, int maxAnimal) : maxAnimals(maxAnimals), name(name){
    Enclosure::currentAnimals = 0;
}

int Enclosure::get_id(void){
    return Enclosure::id;
}

void Enclosure::set_id(int id){
    Enclosure::id = id;
}

std::string Enclosure::get_name(void){
    return Enclosure::name;
}