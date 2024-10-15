#ifndef ENCLOSURETESTS_H
#define ENCLOSURETESTS_H
#include "Enclosure.h"
#include "Zoo.h"

class EnclosureTests : public Enclosure {

    public:
    void run_tests();

    private:

    void test_addAnimal();
};
#endif