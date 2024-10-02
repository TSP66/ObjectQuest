#ifndef LANDENCOLSURE_H
#define LANDENCOLSURE_H

#include "Encolsure.h"

class LandEncolsure: public Encolsure{
    private:
    float area;
    public:
    LandEncolsure(float, int);
    float get_area();
    void set_area(float);
};


#endif