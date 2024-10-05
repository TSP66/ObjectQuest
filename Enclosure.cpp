#include "Enclosure.h"


Enclosure::Enclosure(int maxAnimal) : maxAnimals(maxAnimals) {

}

int Enclosure::get_id(void){
    return Enclosure::id;
}

void Enclosure::set_id(int id){
    Enclosure::id = id;
}