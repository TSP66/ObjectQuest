#include "Animal.h"

Animal::Animal(int id, std::string name) : id(id), name(name){
    Animal::cost = 50;
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