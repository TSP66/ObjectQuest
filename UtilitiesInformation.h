#ifndef UTILITIESINFORMATION_H
#define UTILITIESINFORMATION_H

#include "Information.h"
#include "Utilities.h"

enum UtilityType{
    TOILET,
    FOUNTAIN,
    GIFTSHOP,
};

class UtilitiesInformation: public Information {
    public:
    UtilitiesInformation(std::string, int, int, UtilityType);
    UtilityType type;
    int revenue;
};


#endif