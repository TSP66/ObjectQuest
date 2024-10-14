#include "Animal.h"
//animal class. Used to specify animal features
Animal::Animal(int id, std::string name, int lifespan) : lifespan(lifespan), id(id), name(name){
    Animal::cost = 50;
    Animal::happiness = 100.0;
    Animal::sex = (Sex) (rand() > RAND_MAX/2);
}
//get lifespan used to check the lifespan of animals
float Animal::get_lifespan(){
    return Animal::lifespan;
}
//used to set an animals lifespan
void Animal::set_lifespan(float lifespan){
    Animal::lifespan = lifespan;
}
//used to observe an animals current age
float Animal::get_age(){
    return Animal::age;
}
//used to set an animals age
void Animal::set_age(float age){
    Animal::age = age;
}
//used to observe the animals ID. Each animal receives an ID when created
//This is important for locating specific animals and all their 
//specifications such as age lifespan and happiness
int Animal::get_id(){
    return Animal::id;
}

Death Animal::timestep(){
    return NONE;
}

// used to find animals name 
std::string Animal::get_name(){
    return Animal::name;
}
//comand used to observe an animals cost 
int Animal::get_cost(){
    return Animal::cost;
}

//used to determine an animals 
Sex Animal::get_sex(){
    return Animal::sex;
}
//return animal sex in a string. Ensures user has a way of 
//observing gender while playing 
std::string sexToString(Sex sex){
    switch (sex){
        case MALE:
        return "Male";
        case FEMALE:
        return "Female";
    }
}

//returns how the animal died
//returns a string to the user on the current animals life status
std::string deathToString(Death death){
    switch (death){
        case ILLNESS:
        return "Illness";
        case OLD_AGE:
        return "Old age";
        case STARVATION:
        return "Starvation";
        case NONE:
        return "Did not die!";
    }
}

// returns the specific animals hunger 
float Animal::get_hunger(void){
    return Animal::hunger;
}
//returns the animals happiness 
float Animal::get_happiness(void){
    return Animal::happiness;
}
//sets animals happiness 
void Animal::set_happiness(float happiness){
    Animal::happiness = happiness;
}

void Animal::set_hunger(float hunger){
    Animal::hunger = hunger;
}
//sets the cost of animals

void Animal::set_cost(int cost){
    Animal::cost = cost;
}