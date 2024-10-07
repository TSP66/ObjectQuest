#include "AquaticAnimal.h"

AquaticAnimal::AquaticAnimal(int id, std::string name, int lifespan) : Animal(id, name, lifespan) {

}

bool AquaticAnimal::timestep(){ //Returns true if has died

    AquaticAnimal::age += 7.0/52.0; //Ages one week at a time
    AquaticAnimal::hunger += 1.0;
    AquaticAnimal::happiness -= AquaticAnimal::hunger;

    //Animals die if happiness reaches zero
    if (AquaticAnimal::happiness <= 0){
        return true;
    }
    
    //Animals randomly die as they get older
    if (rand() < (RAND_MAX*AquaticAnimal::age)/(2.0*AquaticAnimal::get_lifespan())){
        return true;
    }   

    return false;
}