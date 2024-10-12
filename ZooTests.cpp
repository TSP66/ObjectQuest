#include "ZooTests.h"
#include <iostream>


void ZooTests::run_tests(){

    ZooTests::test_enclosure_functions();

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

    EnclosureInformation testEnclosure("test",0,LAND,10);

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
    EnclosureInformation testEnclosure2("test2",0,LAND,10);
    Zoo::addEnclosure(testEnclosure2);
    int newNum = enclosureIds.size();
    std::cout<<"new number of enclosures: "<<newNum<<std::endl;
    if (newNum != originalNum + 1){
        std::cout<<"addEnclosure function is not working"<<std::endl;
    } else {
        std::cout<<"addEnclosure function is working"<<std::endl;
    }
}

// void ZooTests::test_mapGetEnclosureById(){

//     std::shared_ptr<Enclosure> enclosure;

//     auto it = enclosures.find(enclosureIds[0]);
//     if (it != enclosures.end()){
//         enclosure = std::shared_ptr<Enclosure>(std::move(it->second));
//     } else {
//         std::cout<<"unable to retrieve enclosure by id:"<<enclosureIds[0]<<std::endl;
//     }

//     if (enclosure->enclosureType == LAND){
//         std::cout<<"unordered map working correctly"<<std::endl;
//     } else {
//         std::cout<<"unordered map not working correctly"<<std::endl;
//     }
// }
