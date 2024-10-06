#ifndef ENCLOSURE_INFORMATION_H
#define ENCLOSURE_INFORMATION_H

#include "Information.h"

enum EnclosureType{
    LAND,
    AQUATIC,
};

class EnclosureInformation: public Information {
    public:
    EnclosureInformation(std::string, int, EnclosureType, float, float);
    EnclosureType type;
    float area;
    float volume;
};


#endif