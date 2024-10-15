#include "AnimalTests.h"
#include "Colours.h"
#include <iostream>

void AnimalTests::run_tests(){
    AnimalTests::test_get_cost();
    AnimalTests::test_set_cost();
    AnimalTests::test_get_lifespan();
    AnimalTests::test_set_lifespan(30);
    AnimalTests::test_get_age();
    AnimalTests::test_set_age(5);
    AnimalTests::test_get_name();
    AnimalTests::test_timestep();
    AnimalTests::test_get_id();
    AnimalTests::test_get_sex();
    AnimalTests::test_get_hunger();
    AnimalTests::test_set_hunger(10);
    AnimalTests::test_get_happiness();
    AnimalTests::test_set_happiness(80);
}

void AnimalTests::test_get_cost(){
    Animal _animal(1234, "animal", 20);
    
    if (_animal.get_cost() != 50){
        std::cout << BOLD << RED << "get_cost function not working" << RESET << std::endl;
    } else {
        std::cout << BOLD << GREEN << "get_cost function is working" << RESET << std::endl;
    }
}

void AnimalTests::test_set_cost(){
    Animal _animal(1234, "animal", 20);
    
    _animal.set_cost(20);

    if (_animal.get_cost() != 20){
        std::cout << BOLD << RED << "set_cost function not working" << RESET << std::endl;
    } else {
        std::cout << BOLD << GREEN << "set_cost function is working" << RESET << std::endl;
    }
}

void AnimalTests::test_get_lifespan(){
    Animal _animal(1234, "animal", 20);

    if (_animal.get_lifespan() != 20){
        std::cout << BOLD << RED << "get_lifespan function not working" << RESET << std::endl;
    } else {
        std::cout << BOLD << GREEN << "get_lifespan function is working" << RESET << std::endl;
    }
}

void AnimalTests::test_set_lifespan(float lifespan){
    Animal _animal(1234, "animal", 20);
    _animal.set_lifespan(lifespan);

    if (_animal.get_lifespan() != lifespan){
        std::cout << BOLD << RED << "set_lifespan function not working" << RESET << std::endl;
    } else {
        std::cout << BOLD << GREEN << "set_lifespan function is working" << RESET << std::endl;
    }
}

void AnimalTests::test_get_age(){
    Animal _animal(1234, "animal", 20);
    _animal.set_age(5);

    if (_animal.get_age() != 5){
        std::cout << BOLD << RED << "get_age function not working" << RESET << std::endl;
    } else {
        std::cout << BOLD << GREEN << "get_age function is working" << RESET << std::endl;
    }
}

void AnimalTests::test_set_age(float age){
    Animal _animal(1234, "animal", 20);
    _animal.set_age(age);

    if (_animal.get_age() != age){
        std::cout << BOLD << RED << "set_age function not working" << RESET << std::endl;
    } else {
        std::cout << BOLD << GREEN << "set_age function is working" << RESET << std::endl;
    }
}

void AnimalTests::test_get_name(){
    Animal _animal(1234, "animal", 20);

    if (_animal.get_name() != "animal"){
        std::cout << BOLD << RED << "get_name function not working" << RESET << std::endl;
    } else {
        std::cout << BOLD << GREEN << "get_name function is working" << RESET << std::endl;
    }
}

void AnimalTests::test_timestep(){
    Animal _animal(1234, "animal", 20);
    if (_animal.timestep() != NONE){
        std::cout << BOLD << RED << "timestep function not working" << RESET << std::endl;
    } else {
        std::cout << BOLD << GREEN << "timestep function is working" << RESET << std::endl;
    }
}

void AnimalTests::test_get_id(){
    Animal _animal(1234, "animal", 20);

    if (_animal.get_id() != 1234){
        std::cout << BOLD << RED << "get_id function not working" << RESET << std::endl;
    } else {
        std::cout << BOLD << GREEN << "get_id function is working" << RESET << std::endl;
    }
}

void AnimalTests::test_get_sex(){
    Animal _animal(1234, "animal", 20);

    if (_animal.get_sex() != MALE && _animal.get_sex() != FEMALE){
        std::cout << BOLD << RED << "get_sex function not working" << RESET << std::endl;
    } else {
        std::cout << BOLD << GREEN << "get_sex function is working" << RESET << std::endl;
    }
}

void AnimalTests::test_get_hunger(){
    Animal _animal(1234, "animal", 20);

    if (_animal.get_hunger() != 0){
        std::cout << BOLD << RED << "get_hunger function not working" << RESET << std::endl;
    } else {
        std::cout << BOLD << GREEN << "get_hunger function is working" << RESET << std::endl;
    }
}

void AnimalTests::test_set_hunger(float hunger){
    Animal _animal(1234, "animal", 20);
    _animal.set_hunger(hunger);

    if (_animal.get_hunger() != hunger){
        std::cout << BOLD << RED << "set_hunger function not working" << RESET << std::endl;
    } else {
        std::cout << BOLD << GREEN << "set_hunger function is working" << RESET << std::endl;
    }
}

void AnimalTests::test_get_happiness(){
    Animal _animal(1234, "animal", 20);

    if (_animal.get_happiness() != 100.0){
        std::cout << BOLD << RED << "get_happiness function not working" << RESET << std::endl;
    } else {
        std::cout << BOLD << GREEN << "get_happiness function is working" << RESET << std::endl;
    }
}

void AnimalTests::test_set_happiness(float happiness){
    Animal _animal(1234, "animal", 20);
    _animal.set_happiness(happiness);

    if (_animal.get_happiness() != happiness){
        std::cout << BOLD << RED << "set_happiness function not working" << RESET << std::endl;
    } else {
        std::cout << BOLD << GREEN << "set_happiness function is working" << RESET << std::endl;
    }
}

void AnimalTests::test_set_cost(int cost){
    Animal _animal(1234, "animal", 20);
    _animal.set_cost(cost);

    if (_animal.get_cost() != cost){
        std::cout << BOLD << RED << "set_cost function not working" << RESET << std::endl;
    } else {
        std::cout << BOLD << GREEN << "set_cost function is working" << RESET << std::endl;
    }
}
