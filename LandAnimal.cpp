#include "LandAnimal.h"

LandAnimal::LandAnimal(int id, std::string name, int lifespan) : Animal(id, name, lifespan) {
    
}

bool LandAnimal::timestep(){ //Returns true if has died

    LandAnimal::age += 7.0/52.0; //Ages one week at a time
    LandAnimal::hunger += 1.0;
    LandAnimal::happiness -= LandAnimal::hunger;

    //Animals die if happiness reaches zero
    if (LandAnimal::happiness <= 0){
        return true;
    }
    
    //Animals randomly die as they get older
    if (rand() < (RAND_MAX*LandAnimal::age)/(2.0*LandAnimal::get_lifespan())){
        return true;
    }   

    return false;
}