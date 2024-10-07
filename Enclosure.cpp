#include "Enclosure.h"


Enclosure::Enclosure(std::string name, int maxAnimals, EnclosureType enclosureType) : maxAnimals(maxAnimals), name(name), enclosureType(enclosureType){
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

bool Enclosure::addAnimal(int id, std::shared_ptr<Animal> animal){
    if (Enclosure::currentAnimals < Enclosure::maxAnimals){
        Enclosure::currentAnimals++;
        Enclosure::animals[id] = animal;
        return true;
    } else {
        return false;
    }
}

bool Enclosure::removeAnimal(int id){
    Enclosure::animals.erase(id);
    Enclosure::currentAnimals--;
    return true; //Sucessfully remove it - need to do better checking in the future
}