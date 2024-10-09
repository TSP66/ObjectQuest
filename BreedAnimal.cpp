#include <iostream>
using namespace std;
#include "Animal.h"
#include "BreedAnimal.h"
#include "Animal.h"

BreedAnimal :: BreedAnimal(Animal animal1, Animal animal2){
    if (animal1.get_age() >= 3 && animal2.get_age() >=3){
        addBabyAnimal();
    }
}