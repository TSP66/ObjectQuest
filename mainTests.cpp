#include "AnimalTests.h"
#include "ZooTests.h"
#include "EnclosureTests.h"
#include "Colours.h"
#include <iostream>


int main(void){

    std::cout<<BOLD<<MAGENTA<<"testing animal.h"<<RESET<<std::endl;
    std::cout<<std::endl;

    AnimalTests _AnimalTests;
    _AnimalTests.run_tests();

    std::cout<<BOLD<<MAGENTA<<"testing animal.h complete"<<RESET<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;

    std::cout<<BOLD<<MAGENTA<<"testing zoo.h"<<RESET<<std::endl;
    std::cout<<std::endl;

    ZooTests _ZooTests;
    _ZooTests.run_tests();

    std::cout<<BOLD<<MAGENTA<<"testing zoo.h complete"<<RESET<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;

    std::cout<<BOLD<<MAGENTA<<"testing enclosure.h"<<RESET<<std::endl;
    std::cout<<std::endl;

    // EnclosureTests EnclosureTests;
    // EnclosureTests.run_tests();
}