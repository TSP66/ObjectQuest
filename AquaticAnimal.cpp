#include "AquaticAnimal.h"

AquaticAnimal::AquaticAnimal(int id) : Animal(id) {

}

bool AquaticAnimal::timestep(){
    return true;
}