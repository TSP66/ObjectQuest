#ifndef LANDENCOLSURE_H
#define LANDENCOLSURE_H

#include "Enclosure.h"

class LandEnclosure: public Enclosure{
    private:
    float area;
    
    public:
    LandEnclosure();
    LandEnclosure(float, int);
    float get_area();
    void set_area(float);
};


#endif