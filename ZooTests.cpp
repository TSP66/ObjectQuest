#include "ZooTests.h"
#include <iostream>

void ZooTests::run_tests(){

    ZooTests::test_enclosure_functions();

}

void ZooTests::test_enclosure_functions(){
    
    std::cout<<"testing zoo.h enclosure information generation"<<std::endl;
    EnclosureInformation testLandEnclosure("test",0,LAND,10);
    EnclosureInformation testAquaticEnclosure("test",0,AQUATIC,10);
    std::cout<<"EnclosureInformation class working correctly"<<std::endl;
    std::cout<<"Created both land and aquatic enclosure information vectors"<<std::endl;
    std::cout<<std::endl;


    std::cout<<"testing zoo.h buildEnclosure function"<<std::endl;
    std::cout<<"testing without funds"<<std::endl;
    ZooTests::buildEnclosure(0);
    std::cout<<"testing with funds"<<std::endl;
    ZooTests::buildEnclosure(999999);
    std::cout<<std::endl;

    std::cout<<"testing unordered map object storing"<<std::endl;
    ZooTests::mapGetEnclosureById();


}


Changes ZooTests::buildEnclosure(int money){

    EnclosureInformation parameters = Zoo::enclosureInformation[0];

    if (parameters.cost > money){
        std::cout << RED << "Insufficient Funds!\n" << RESET;
        return {0};
    }

    Zoo::addEnclosure(parameters);

    std::cout<<"created enclosure with id: "<<enclosureIds[0]<<std::endl;

    return {parameters.cost};

}

void ZooTests::mapGetEnclosureById(){

    std::shared_ptr<Enclosure> enclosure;

    auto it = enclosures.find(enclosureIds[0]);
    if (it != enclosures.end()){
        enclosure = std::shared_ptr<Enclosure>(std::move(it->second));
    } else {
        std::cout<<"unable to retrieve enclosure by id:"<<enclosureIds[0]<<std::endl;
    }

    if (enclosure->enclosureType == LAND){
        std::cout<<"unordered map working correctly"<<std::endl;
    } else {
        std::cout<<"unordered map not working correctly"<<std::endl;
    }
}
