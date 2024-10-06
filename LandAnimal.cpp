#include "LandAnimal.h"

LandAnimal::LandAnimal(int id, std::string name) : Animal(id, name) {
    
}

bool LandAnimal::timestep(){
    return true;
}