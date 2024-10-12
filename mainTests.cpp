#include "AnimalTests.h"
#include "Zootests.h"
#include <iostream>

int main(void){

    std::cout<<"testing animal.h"<<std::endl;

    AnimalTests _AnimalTests;
    _AnimalTests.run_tests();

    std::cout<<"testing animal.h complete"<<std::endl;
    std::cout<<std::endl;
    std::cout<<std::endl;

    std::cout<<"testing zoo.h"<<std::endl;

    ZooTests _ZooTests;
    _ZooTests.run_tests();

    std::cout<<"testing zoo.h complete"<<std::endl;
}