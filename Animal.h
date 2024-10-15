#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

enum Sex{
    MALE,
    FEMALE,
};

enum Death{
    NONE,
    STARVATION,
    ILLNESS,
    OLD_AGE,
};

//these functions are all the getters and 
//setters for the animals variables 
//this can be anything from age to death to hunger
class Animal{
    private:
    float lifespan;
    int cost;
    int id;
    std::string name;
    protected:
    float age;
    float hunger;
    float happiness;
    Sex sex; //Sex 
    public:
    int enclosureID;
    Animal(int id, std::string name, int);
    int get_cost();
    float get_lifespan();
    void set_lifespan(float);
    float get_age();
    std::string get_name();
    void set_age(float);
    virtual Death timestep();
    int get_id();
    Sex get_sex();
    float get_hunger(void);
    float get_happiness(void);
    void set_happiness(float);
    void set_hunger(float);
    void set_cost(int);
    virtual ~Animal() {}
};

std::string sexToString(Sex);
std::string deathToString(Death);

#endif

//
//
//