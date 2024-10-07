#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

enum Sex{
    MALE,
    FEMALE,
};

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
    virtual bool timestep();
    int get_id();
    virtual ~Animal() {}
};

#endif