#include "LandAnimal.h"

LandAnimal::LandAnimal(int id) : Animal(id) {
    
}

bool LandAnimal::timestep(){
    return true;
}