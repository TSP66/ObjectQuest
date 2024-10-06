#ifndef ANIMALINFORMATION_H
#define ANIMALINFORMATION_H

#include "Information.h"
#include "EnclosureInformation.h"
#include "AnimalMacros.h"


class AnimalInformation: public Information{
    public:
    Animals type;
    EnclosureType enclosureType;
    AnimalInformation(std::string, int, Animals, EnclosureType);
    //Other stuff that we may need to create an Animal object
};

#endif