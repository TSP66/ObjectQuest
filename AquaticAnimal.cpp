#include "AquaticAnimal.h"

AquaticAnimal::AquaticAnimal(int id, std::string name, int lifespan) : Animal(id, name, lifespan) {
}

Death AquaticAnimal::timestep(){// Returns true if has died

    AquaticAnimal::age += 7.0/52.0;// Ages one week at a time
    AquaticAnimal::hunger += 1.0;
    AquaticAnimal::happiness -= AquaticAnimal::hunger;
 
// Animals die if happiness reaches zero
    if (AquaticAnimal::happiness <= 0){
        return STARVATION;
    }
    
// Animals randomly die as they get older
    if (rand() < (RAND_MAX*AquaticAnimal::age)/(2.0*AquaticAnimal::get_lifespan())){
        if (AquaticAnimal::age >= (3*AquaticAnimal::get_lifespan())/4){
            return OLD_AGE;
        }
        return ILLNESS;
    }   
    return NONE;
}

//
//
//