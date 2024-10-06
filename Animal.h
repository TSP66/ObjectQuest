#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>

class Animal{
    private:
    int lifespan;
    int age;
    float hunger;
    float happiness;
    int cost;
    int id;
    std::string name;
    public:
    Animal(int id, std::string name);
    int get_lifespan();
    void set_lifespan(int);
    int get_age();
    std::string get_name();
    void set_age(int);
    virtual bool timestep();
    int get_id();
    virtual ~Animal() {}
};

#endif