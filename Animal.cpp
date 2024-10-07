#include "Animal.h"

Animal::Animal(int id, std::string name, int lifespan) : id(id), name(name), lifespan(lifespan){
    Animal::cost = 50;
    Animal::happiness = 100.0;
    Animal::sex = (Sex) (rand() > RAND_MAX/2);
}

float Animal::get_lifespan(){
    return Animal::lifespan;
}
void Animal::set_lifespan(float lifespan){
    Animal::lifespan = lifespan;
}
float Animal::get_age(){
    return Animal::age;
}
void Animal::set_age(float age){
    Animal::age = age;
}

int Animal::get_id(){
    return Animal::id;
}

bool Animal::timestep(){
    return false;
}

std::string Animal::get_name(){
    return Animal::name;
}

int Animal::get_cost(){
    return Animal::cost;
}

Sex Animal::get_sex(){
    return Animal::sex;
}

std::string sexToString(Sex sex){
    switch (sex){
        case MALE:
        return "Male";
        case FEMALE:
        return "Female";
    }
}

float Animal::get_hunger(void){
    return Animal::hunger;
}
float Animal::get_happiness(void){
    return Animal::happiness;
}

void Animal::set_happiness(float happiness){
    Animal::happiness = happiness;
}

void Animal::set_hunger(float hunger){
    Animal::hunger = hunger;
}