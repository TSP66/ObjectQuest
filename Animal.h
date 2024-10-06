#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal{
    private:
    float lifespan;
    float age;
    float hunger;
    float happiness;
    int cost;
    int id;
    std::string name;
    public:
    Animal(int id, std::string name);
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