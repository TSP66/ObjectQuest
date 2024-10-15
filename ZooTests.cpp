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
    std::cout<<BOLD<<BLUE<<"testing zoo.h enclosure information generation"<<RESET<<std::endl;

    EnclosureInformation testEnclosure("testenclosure",0,LAND,10);

    if (testEnclosure.type == LAND && testEnclosure.cost == 0 && testEnclosure.maxAnimals == 10 ){
        std::cout<<BOLD<<GREEN<<"EnclosureInformation class working correctly"<<RESET<<std::endl;
    } else {
        std::cout<<BOLD<<RED<<"EnclosureInformation class not working correctly"<<RESET<<std::endl;
    }
    

}

void ZooTests::test_buildEnclosure(){

    std::cout<<BOLD<<BLUE<<"testing zoo.h buildEnclosure function"<<RESET<<std::endl;
    std::cout<<BOLD<<BLUE<<"testing without funds"<<RESET<<std::endl;
    Changes resultWithoutFunds = Zoo::buildEnclosure(0);
    std::cout<<resultWithoutFunds.returnMessage<<std::endl;
    std::cout<<BOLD<<BLUE<<"testing with funds"<<RESET<<std::endl;
    Changes resultWithFunds = Zoo::buildEnclosure(999999);
    std::cout<<resultWithFunds.returnMessage<<std::endl;

    std::cout<<std::endl;
}

void ZooTests::test_addEnclosure(){


    std::cout<<BOLD<<BLUE<<"testing addEnclosure function"<<RESET<<std::endl;
    int originalNum = enclosureIds.size();
    std::cout<<BOLD<<BLUE<<"original number of enclosures: "<<RESET<<originalNum<<std::endl;
    EnclosureInformation testEnclosure2("testenclosure2",0,LAND,10);
    Zoo::addEnclosure(testEnclosure2);
    int newNum = enclosureIds.size();
    std::cout<<BOLD<<BLUE<<"new number of enclosures: "<<newNum<<RESET<<std::endl;
    if (newNum != originalNum + 1){
        std::cout<<BOLD<<RED<<"addEnclosure function is not working"<<RESET<<std::endl;
    } else {
        std::cout<<BOLD<<GREEN<<"addEnclosure function is working"<<RESET<<std::endl;
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

    std::cout<<BOLD<<BLUE<<"testing zoo.h animal information generation"<<RESET<<std::endl;

    AnimalInformation testAnimal("Lion",PRICE_ANIMAL(Lion),CAPITALIZE_ANIMAL(Lion),LAND);

    if (testAnimal.enclosureType == LAND && testAnimal.cost == 30 && testAnimal.type == LION ){
        std::cout<<BOLD<<GREEN<<"AnimalInformation class working correctly"<<RESET<<std::endl;
    } else {
        std::cout<<BOLD<<RED<<"AnimalInformation class is not working correctly"<<RESET<<std::endl;
    }
}

void ZooTests::test_buyAnimal(){

    std::cout<<BOLD<<BLUE<<"testing zoo.h buyAnimal function"<<RESET<<std::endl;

    std::cout<<BOLD<<BLUE<<"testing without funds"<<RESET<<std::endl;
    Changes resultWithoutFunds = Zoo::buyAnimal(0);
    std::cout<<resultWithoutFunds.returnMessage<<std::endl;

    std::cout<<BOLD<<BLUE<<"testing with funds"<<RESET<<std::endl;
    Changes resultWithFunds = Zoo::buyAnimal(999999);
    std::cout<<resultWithFunds.returnMessage<<std::endl;

    std::cout<<BOLD<<BLUE<<"testing without enclosure"<<RESET<<std::endl;
    enclosureIds.clear();
    Changes resultWithoutEnclosures = Zoo::buyAnimal(999999);
    std::cout<<resultWithoutEnclosures.returnMessage<<std::endl;

    std::cout<<BOLD<<BLUE<<"testing with wrong enclosure"<<RESET<<std::endl;
    EnclosureInformation testEnclosure4("testenclosure4",0,AQUATIC,10);
    Zoo::addEnclosure(testEnclosure4);
    Changes resultWithWrongEnclosure = Zoo::buyAnimal(999999);
    std::cout<<resultWithWrongEnclosure.returnMessage<<std::endl;
}

void ZooTests::test_deleteAnimal(){

    std::cout<<BOLD<<BLUE<<"testsing zoo.h deleteAnimal function"<<RESET<<std::endl;

    EnclosureInformation testEnclosure3("testenclosure3",0,LAND,10);
    Zoo::addEnclosure(testEnclosure3);
    animalIds.clear();
    Changes _test = Zoo::buyAnimal(999999);

    int newAnimalId = Zoo::animalIds[0];

    int originalNum = animalIds.size();

    deleteAnimal(newAnimalId);
    int newNum = animalIds.size();

    if ((originalNum != 1) || (newNum != 0)){
        std::cout<<BOLD<<RED<<"deleteAnimal function is not working"<<RESET<<std::endl;
    } else {
        std::cout<<BOLD<<GREEN<<"deleteAnimal function is working"<<RESET<<std::endl;
    }
}

void ZooTests::test_feedAnimal(){

    std::cout<<BOLD<<BLUE<<"testing feedAnimal function"<<RESET<<std::endl;

    std::cout<<BOLD<<BLUE<<"testing without any animals"<<RESET<<std::endl;
    animalIds.clear();
    Changes _test = feedAnimal(999999);
    std::cout<<_test.returnMessage<<std::endl;

    Changes _testAnimal = buyAnimal(999999);

    std::cout<<BOLD<<BLUE<<"testing without funds"<<RESET<<std::endl;
    _test = feedAnimal(0);
    std::cout<<_test.returnMessage<<std::endl;


    std::cout<<BOLD<<BLUE<<"testing with animals and funds"<<RESET<<std::endl;
    int Id = Zoo::animalIds[0];
    Zoo::animals[Id]->set_hunger(99.0);
    float originalHunger = Zoo::animals[Id]->get_hunger();


    std::cout<<BOLD<<BLUE<<"Original animal hunger: "<<originalHunger<<RESET<<std::endl;
    _test = feedAnimal(99999);
    float newHunger = Zoo::animals[Id]->get_hunger();
    std::cout<<BOLD<<BLUE<<"New animal hunger: "<<newHunger<<RESET<<std::endl;

    std::cout<<_test.returnMessage<<std::endl;

    //see if i can get it to print animalsToFeed.push_back
}

void ZooTests::test_sellAnimal(){

    std::cout<<BOLD<<BLUE<<"testing sellAnimal function"<<RESET<<std::endl;

    std::cout<<BOLD<<BLUE<<"testing without any animals"<<RESET<<std::endl;
    animalIds.clear();
    Changes _test = sellAnimal();
    std::cout<<_test.returnMessage<<std::endl;



    std::cout<<BOLD<<BLUE<<"testing with animals"<<RESET<<std::endl;
    animalIds.clear();

    // Player _testPlayer(1000);
    // std::cout<<"Current player money: "<<_testPlayer.money<<std::endl;
    
    _test = buyAnimal(99999);
    _test = sellAnimal();

    // std::cout<<"New player money: "<<_testPlayer.money<<std::endl;
    // // money doesnt go to player for some reason

    if (animalIds.size()!=0){
        std::cout<<BOLD<<RED<<"sellAnimal function did not delete the animal and is not working"<<RESET<<std::endl;
    } else {
        std::cout<<BOLD<<GREEN<<"sellAnimal function deleted the animal and is working"<<RESET<<std::endl;
    }
}

void ZooTests::test_moveAnimal(){

    std::cout<<BOLD<<BLUE<<"testing moveAnimal function"<<RESET<<std::endl;

    std::cout<<BOLD<<BLUE<<"testing without any animals"<<RESET<<std::endl;
    animalIds.clear();
    enclosureIds.clear();
    Changes _test = moveAnimal();
    std::cout<<_test.returnMessage<<std::endl;
    std::cout<<std::endl;


    std::cout<<BOLD<<BLUE<<"testing with animals and one enclosure"<<RESET<<std::endl;

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

    std::cout<<BOLD<<BLUE<<"testing with animals and multiple enclosures"<<RESET<<std::endl;

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
    std::cout<<BOLD<<BLUE<<"testing breadAnimals function"<<RESET<<std::endl;

    animalIds.clear();
    enclosureIds.clear();

    std::cout<<BOLD<<BLUE<<"testing with less than two animals"<<RESET<<std::endl;

    EnclosureInformation testEnclosure2("testenclosure2",0,LAND,10);
    Zoo::addEnclosure(testEnclosure2);

    Changes _testAnimal = buyAnimal(9999);
    std::cout<<_testAnimal.returnMessage<<std::endl;

    Changes _testBreeding = breadAnimals(99999);
    std::cout<<_testBreeding.returnMessage<<std::endl; 
    std::cout<<std::endl;

    std::cout<<BOLD<<BLUE<<"testing with two animals and no funds"<<RESET<<std::endl;

    Changes _testAnimal2 = buyAnimal(9999);
    std::cout<<_testAnimal2.returnMessage<<std::endl;

    Changes _testBreeding2 = breadAnimals(0);
    std::cout<<_testBreeding2.returnMessage<<std::endl; 
    std::cout<<std::endl;

    std::cout<<BOLD<<BLUE<<"testing with two young animals and funds"<<RESET<<std::endl;

    Changes _testBreeding3 = breadAnimals(99999);
    std::cout<<_testBreeding3.returnMessage<<std::endl; 
    std::cout<<std::endl;

    std::cout<<BOLD<<BLUE<<"testing with two older animals and funds"<<RESET<<std::endl;

    for (int i=0;i<animalIds.size();i++){
        Animal* animal = Zoo::animals[animalIds[i]].get();
        animal->set_age(6);
    }

    Changes _testBreeding4 = breadAnimals(99999);
    std::cout<<_testBreeding4.returnMessage<<std::endl;

    std::cout<<BOLD<<BLUE<<"checking if animal was added to the enclosure"<<RESET<<std::endl;

    if (animalIds.size()!= 3){
        std::cout<<BOLD<<RED<<"new animals id was not added to id vector"<<RESET<<std::endl;
    } else {
        std::cout<<BOLD<<GREEN<<"new animals id was successfully added to id vector"<<RESET<<std::endl;
        Animal* animal3 = Zoo::animals[animalIds[2]].get();
        std::cout<<BOLD<<BLUE<<"a new lion with age: "<<animal3->get_age()<<RESET<<std::endl;
    }

}

// void ZooTests::test_goToBank(){

//     std::cout<<"testing goToBank function"<<std::endl;

//     std::cout<<"testing pay loan"<<std::endl;


// }