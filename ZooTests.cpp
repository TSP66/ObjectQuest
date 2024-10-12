#include "ZooTests.h"
#include <iostream>


void ZooTests::run_tests(){

    ZooTests::test_enclosure_functions();

    ZooTests::test_animal_functions();

}

void ZooTests::test_enclosure_functions(){

    ZooTests::test_EnclosureInformation();
    std::cout<<std::endl;

    ZooTests::test_addEnclosure();
    std::cout<<std::endl;

    ZooTests::test_buildEnclosure();
    
}

void ZooTests::test_EnclosureInformation(){
    std::cout<<"testing zoo.h enclosure information generation"<<std::endl;

    EnclosureInformation testEnclosure("testenclosure",0,LAND,10);

    if (testEnclosure.type == LAND && testEnclosure.cost == 0 && testEnclosure.maxAnimals == 10 ){
        std::cout<<"EnclosureInformation class working correctly"<<std::endl;
    }
    

}

void ZooTests::test_buildEnclosure(){

    std::cout<<"testing zoo.h buildEnclosure function"<<std::endl;
    std::cout<<"testing without funds"<<std::endl;
    Changes resultWithoutFunds = Zoo::buildEnclosure(0);
    std::cout<<resultWithoutFunds.returnMessage<<std::endl;
    std::cout<<"testing with funds"<<std::endl;
    Changes resultWithFunds = Zoo::buildEnclosure(999999);
    std::cout<<resultWithFunds.returnMessage<<std::endl;

    std::cout<<std::endl;
}

void ZooTests::test_addEnclosure(){


    std::cout<<"testing addEnclosure function"<<std::endl;
    int originalNum = enclosureIds.size();
    std::cout<<"original number of enclosures: "<<originalNum<<std::endl;
    EnclosureInformation testEnclosure2("testenclosure2",0,LAND,10);
    Zoo::addEnclosure(testEnclosure2);
    int newNum = enclosureIds.size();
    std::cout<<"new number of enclosures: "<<newNum<<std::endl;
    if (newNum != originalNum + 1){
        std::cout<<"addEnclosure function is not working"<<std::endl;
    } else {
        std::cout<<"addEnclosure function is working"<<std::endl;
    }
}

void ZooTests::test_animal_functions(){

    ZooTests::test_AnimalInformation();
    std::cout<<std::endl;

    // ZooTests::test_addAnimal();
    // std::cout<<std::endl;

    ZooTests::test_buyAnimal();
    
}

void ZooTests::test_AnimalInformation(){

    std::cout<<"testing zoo.h animal information generation"<<std::endl;

    AnimalInformation testAnimal("Lion",PRICE_ANIMAL(Lion),CAPITALIZE_ANIMAL(Lion),LAND);

    if (testAnimal.enclosureType == LAND && testAnimal.cost == 30 && testAnimal.type == LION ){
        std::cout<<"AnimalInformation class working correctly"<<std::endl;
    }
    // need test more annimal attributes
}





// void ZooTests::test_addAnimal(){
//     std::cout<<"testing addAnimal function"<<std::endl;
//     int originalNum = animalIds.size();
//     std::cout<<"original number of animals: "<<originalNum<<std::endl;
//     AnimalInformation testAnimal2("testanimal",0,LAND,10);


//     Zoo::addAnimal("Lion",PRICE_ANIMAL(Lion),CAPITALIZE_ANIMAL(Lion),LAND);
    
//     int newNum = animalIds.size();
//     std::cout<<"new number of animals: "<<newNum<<std::endl;
//     if (newNum != originalNum + 1){
//         std::cout<<"addAnimals function is not working"<<std::endl;
//     } else {
//         std::cout<<"addAnimals function is working"<<std::endl;
//     }
// }

void ZooTests::test_buyAnimal(){

    std::cout<<"testing zoo.h buyAnimal function"<<std::endl;

    std::cout<<"testing without funds"<<std::endl;
    Changes resultWithoutFunds = Zoo::buyAnimal(0);
    std::cout<<resultWithoutFunds.returnMessage<<std::endl;

    std::cout<<"testing with funds"<<std::endl;
    Changes resultWithFunds = Zoo::Zoo::buyAnimal(999999);
    std::cout<<resultWithFunds.returnMessage<<std::endl;

    std::cout<<"testing without enclosure"<<std::endl;
    enclosureIds.clear();
    Changes resultWithoutEnclosures = Zoo::Zoo::buyAnimal(999999);
    std::cout<<resultWithoutEnclosures.returnMessage<<std::endl;
    
}