#ifndef ZOOTESTS_H
#define ZOOTESTS_H



#include "Zoo.h"

class ZooTests : public Zoo {
    public:
    void run_tests();

    private:
    void test_enclosure_functions();

    void test_EnclosureInformation();

    void test_buildEnclosure();

    void test_addEnclosure();


    void test_animal_functions();

    void test_AnimalInformation();

    void test_buyAnimal();

    void test_deleteAnimal();

    void test_feedAnimal();

    void test_sellAnimal();

    void test_moveAnimal();

    void test_breadAnimals();


    // void test_goToBank();


};




#endif