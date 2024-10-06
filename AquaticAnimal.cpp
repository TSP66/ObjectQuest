#include "AquaticAnimal.h"

AquaticAnimal::AquaticAnimal(int id, std::string name) : Animal(id, name) {

}

bool AquaticAnimal::timestep(){
    return true;
}