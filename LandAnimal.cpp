#include "LandAnimal.h"

LandAnimal::LandAnimal(int id, std::string name, int lifespan) : Animal(id, name, lifespan) {
    
}

Death LandAnimal::timestep(){ //Returns true if has died

    LandAnimal::age += 7.0/52.0; //Ages one week at a time
    LandAnimal::hunger += 1.0;
    LandAnimal::happiness -= LandAnimal::hunger;

    //Animals die if happiness reaches zero
    if (LandAnimal::happiness <= 0){
        return STARVATION;
    }
    
    //Animals randomly die as they get older
    if (rand() < (RAND_MAX*LandAnimal::age)/(2.0*LandAnimal::get_lifespan())){
        if (LandAnimal::age >= (3*LandAnimal::get_lifespan())/4){
            return OLD_AGE;
        }
        return ILLNESS;
    }   

    return NONE;

}