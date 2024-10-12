#ifndef ANIMALTESTS_H
#define ANIMALTESTS_H

#include <string>
#include "Animal.h"

class AnimalTests {
    public:
    void run_tests();

    private:
        void test_get_cost();
        void test_set_cost();
        void test_get_lifespan();
        void test_set_lifespan(float);
        void test_get_age();
        void test_get_name();
        void test_set_age(float);
        void test_timestep();
        void test_get_id();
        void test_get_sex();
        void test_get_hunger(void);
        void test_get_happiness(void);
        void test_set_happiness(float);
        void test_set_hunger(float);
        void test_set_cost(int);
};

#endif