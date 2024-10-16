#ifndef ENCLOSURE_INFORMATION_H
#define ENCLOSURE_INFORMATION_H

#include "Information.h"

enum EnclosureType{ //determines the type of enclosure.
    LAND,
    AQUATIC,
};

class EnclosureInformation: public Information {
    public:
    EnclosureInformation(std::string, int, EnclosureType, int);
    EnclosureType type; 
    int maxAnimals;
};


#endif