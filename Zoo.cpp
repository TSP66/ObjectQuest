#include "Zoo.h"

Zoo::Zoo(){

}

void Zoo::addAnimal(std::shared_ptr<Animal> animal){
    Zoo::animals[animal->get_id()] = animal;
}

