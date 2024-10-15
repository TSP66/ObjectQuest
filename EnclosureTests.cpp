#include "EnclosureTests.h"
#include <iostream>

void EnclosureTests::run_tests(){
    return 0;
}

void EnclosureTests::test_addAnimal(){

    std::cout<<"testing addAnimal function"<<std::endl;

    animalIds.clear();
    enclosureIds.clear();

    Zoo::Changes _newAnimal = buyAnimal(9999);
    int id = animalIds[0];

    Animal* animal = Zoo::animals[animalIds[id]].get();



}