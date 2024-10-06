#ifndef ANIMAL_H
#define ANIMAL_H

class Animal{
    private:
    int lifespan;
    int age;
    float hunger;
    float happiness;
    int cost;
    int id;
    public:
    Animal(int id);
    int get_lifespan();
    void set_lifespan(int);
    int get_age();
    void set_age(int);
    virtual bool timestep();
    int get_id();
};

#endif