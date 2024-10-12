#ifndef ZOOTESTS_H
#define ZOOTESTS_H

#include "Zoo.h"

class ZooTests : public Zoo {
    public:
    void run_tests();

    private:
    void test_enclosure_functions();

    Changes buildEnclosure(int) override;

    void mapGetEnclosureById();


};




#endif