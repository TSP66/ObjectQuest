#include "ZooTests.h"
#include "Player.h"
#include <iostream>


void ZooTests::run_tests(){

    ZooTests::test_enclosure_functions();

    ZooTests::test_animal_functions();

    // ZooTests::test_goToBank();

}

void ZooTests::test_enclosure_functions(){

    ZooTests::test_EnclosureInformation();
    std::cout<<std::endl;

    ZooTests::test_addEnclosure();
    std::cout<<std::endl;

    ZooTests::test_buildEnclosure();
    std::cout<<std::endl;
    
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

    ZooTests::test_buyAnimal();
    std::cout<<std::endl;

    ZooTests::test_deleteAnimal();
    std::cout<<std::endl;

    ZooTests::test_feedAnimal();
    std::cout<<std::endl;

    ZooTests::test_sellAnimal();
    std::cout<<std::endl;

    ZooTests::test_moveAnimal();
    std::cout<<std::endl;

    ZooTests::test_breadAnimals();
}

void ZooTests::test_AnimalInformation(){

    std::cout<<"testing zoo.h animal information generation"<<std::endl;

    AnimalInformation testAnimal("Lion",PRICE_ANIMAL(Lion),CAPITALIZE_ANIMAL(Lion),LAND);

    if (testAnimal.enclosureType == LAND && testAnimal.cost == 30 && testAnimal.type == LION ){
        std::cout<<"AnimalInformation class working correctly"<<std::endl;
    }
}

void ZooTests::test_buyAnimal(){

    std::cout<<"testing zoo.h buyAnimal function"<<std::endl;

    std::cout<<"testing without funds"<<std::endl;
    Changes resultWithoutFunds = Zoo::buyAnimal(0);
    std::cout<<resultWithoutFunds.returnMessage<<std::endl;

    std::cout<<"testing with funds"<<std::endl;
    Changes resultWithFunds = Zoo::buyAnimal(999999);
    std::cout<<resultWithFunds.returnMessage<<std::endl;

    std::cout<<"testing without enclosure"<<std::endl;
    enclosureIds.clear();
    Changes resultWithoutEnclosures = Zoo::buyAnimal(999999);
    std::cout<<resultWithoutEnclosures.returnMessage<<std::endl;

    std::cout<<"testing with wrong enclosure"<<std::endl;
    EnclosureInformation testEnclosure4("testenclosure4",0,AQUATIC,10);
    Zoo::addEnclosure(testEnclosure4);
    Changes resultWithWrongEnclosure = Zoo::buyAnimal(999999);
    std::cout<<resultWithWrongEnclosure.returnMessage<<std::endl;
}

void ZooTests::test_deleteAnimal(){

    std::cout<<"testsing zoo.h deleteAnimal function"<<std::endl;

    EnclosureInformation testEnclosure3("testenclosure3",0,LAND,10);
    Zoo::addEnclosure(testEnclosure3);
    animalIds.clear();
    Changes _test = Zoo::buyAnimal(999999);

    int newAnimalId = Zoo::animalIds[0];

    int originalNum = animalIds.size();

    deleteAnimal(newAnimalId);
    int newNum = animalIds.size();

    if ((originalNum != 1) || (newNum != 0)){
        std::cout<<"deleteAnimal function is not working"<<std::endl;
    } else {
        std::cout<<"deleteAnimal function is working"<<std::endl;
    }
}

void ZooTests::test_feedAnimal(){

    std::cout<<"testing feedAnimal function"<<std::endl;

    std::cout<<"testing without any animals"<<std::endl;
    animalIds.clear();
    Changes _test = feedAnimal(999999);
    std::cout<<_test.returnMessage<<std::endl;

    Changes _testAnimal = buyAnimal(999999);

    std::cout<<"testing without funds"<<std::endl;
    _test = feedAnimal(0);
    std::cout<<_test.returnMessage<<std::endl;


    std::cout<<"testing with animals and funds"<<std::endl;
    int Id = Zoo::animalIds[0];
    Zoo::animals[Id]->set_hunger(99.0);
    float originalHunger = Zoo::animals[Id]->get_hunger();


    std::cout<<"Original animal hunger: "<<originalHunger<<std::endl;
    _test = feedAnimal(99999);
    float newHunger = Zoo::animals[Id]->get_hunger();
    std::cout<<"New animal hunger: "<<newHunger<<std::endl;

    std::cout<<_test.returnMessage<<std::endl;

    //see if i can get it to print animalsToFeed.push_back
}

void ZooTests::test_sellAnimal(){

    std::cout<<"testing sellAnimal function"<<std::endl;

    std::cout<<"testing without any animals"<<std::endl;
    animalIds.clear();
    Changes _test = sellAnimal();
    std::cout<<_test.returnMessage<<std::endl;



    std::cout<<"testing with animals"<<std::endl;
    animalIds.clear();

    // Player _testPlayer(1000);
    // std::cout<<"Current player money: "<<_testPlayer.money<<std::endl;
    
    _test = buyAnimal(99999);
    _test = sellAnimal();

    // std::cout<<"New player money: "<<_testPlayer.money<<std::endl;
    // // money doesnt go to player for some reason

    if (animalIds.size()!=0){
        std::cout<<"sellAnimal function did not delete the animal and is not working"<<std::endl;
    } else {
        std::cout<<"sellAnimal function deleted the animal and is working"<<std::endl;
    }
}

void ZooTests::test_moveAnimal(){

    std::cout<<"testing moveAnimal function"<<std::endl;

    std::cout<<"testing without any animals"<<std::endl;
    animalIds.clear();
    enclosureIds.clear();
    Changes _test = moveAnimal();
    std::cout<<_test.returnMessage<<std::endl;
    std::cout<<std::endl;


    std::cout<<"testing with animals and one enclosure"<<std::endl;

    animalIds.clear();
    enclosureIds.clear();

    EnclosureInformation testEnclosure3("testenclosure3",0,LAND,10);
    Zoo::addEnclosure(testEnclosure3);
    // EnclosureInformation testEnclosure2("testenclosure2",0,LAND,10);
    // Zoo::addEnclosure(testEnclosure2);

    Changes _testAnimal = buyAnimal(9999);
    std::cout<<_testAnimal.returnMessage<<std::endl;

    // Animal* animal = Zoo::animals[animalIds[0]].get();
    // std::cout<<animal->get_name()<<std::endl;

    // for (int i=0;i<enclosureIds.size();i++){
    //     std::cout<<enclosureIds[i]<<std::endl;
    // }

    
    // for (int i=0;i<animalIds.size();i++){
    //     std::cout<<animalIds[i]<<std::endl;
    // }

    Changes _testMove = moveAnimal();
    std::cout<<_testMove.returnMessage<<std::endl;
    std::cout<<std::endl;

    std::cout<<"testing with animals and multiple enclosures"<<std::endl;

    animalIds.clear();
    enclosureIds.clear();

    EnclosureInformation testEnclosure2("testenclosure2",0,LAND,10);
    Zoo::addEnclosure(testEnclosure2);
    Zoo::addEnclosure(testEnclosure3);

    Changes _testAnimal2 = buyAnimal(9999);
    std::cout<<_testAnimal2.returnMessage<<std::endl;

    Changes _testMove2 = moveAnimal();
    std::cout<<_testMove2.returnMessage<<std::endl;
}

void ZooTests::test_breadAnimals(){
    std::cout<<"testing breadAnimals function"<<std::endl;

    animalIds.clear();
    enclosureIds.clear();

    std::cout<<"testing with less than two animals"<<std::endl;

    EnclosureInformation testEnclosure2("testenclosure2",0,LAND,10);
    Zoo::addEnclosure(testEnclosure2);

    Changes _testAnimal = buyAnimal(9999);
    std::cout<<_testAnimal.returnMessage<<std::endl;

    Changes _testBreeding = breadAnimals(99999);
    std::cout<<_testBreeding.returnMessage<<std::endl; 
    std::cout<<std::endl;

    std::cout<<"testing with two animals and no funds"<<std::endl;

    Changes _testAnimal2 = buyAnimal(9999);
    std::cout<<_testAnimal2.returnMessage<<std::endl;

    Changes _testBreeding2 = breadAnimals(0);
    std::cout<<_testBreeding2.returnMessage<<std::endl; 
    std::cout<<std::endl;

    std::cout<<"testing with two young animals and funds"<<std::endl;

    Changes _testBreeding3 = breadAnimals(99999);
    std::cout<<_testBreeding3.returnMessage<<std::endl; 
    std::cout<<std::endl;

    std::cout<<"testing with two older animals and funds"<<std::endl;

    for (int i=0;i<animalIds.size();i++){
        Animal* animal = Zoo::animals[animalIds[i]].get();
        animal->set_age(6);
    }

    Changes _testBreeding4 = breadAnimals(99999);
    std::cout<<_testBreeding4.returnMessage<<std::endl;

    std::cout<<"checking if animal was added to the enclosure"<<std::endl;

    if (animalIds.size()!= 3){
        std::cout<<"new animals id was not added to id vector"<<std::endl;
    } else {
        std::cout<<"new animals id was successfully added to id vector"<<std::endl;
        Animal* animal3 = Zoo::animals[animalIds[2]].get();
        std::cout<<"A new lion with age: "<<animal3->get_age()<<std::endl;
    }

}

// void ZooTests::test_goToBank(){

//     std::cout<<"testing goToBank function"<<std::endl;

//     std::cout<<"testing pay loan"<<std::endl;


// }