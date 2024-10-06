#include "Animal.h"

Animal::Animal(int id, std::string name) : id(id), name(name){

}

int Animal::get_lifespan(){
    return Animal::lifespan;
}
void Animal::set_lifespan(int lifespan){
    Animal::lifespan = lifespan;
}
int Animal::get_age(){
    return Animal::age;
}
void Animal::set_age(int age){
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