#ifndef ANIMALINFORMATION_H
#define ANIMALINFORMATION_H

#include "Information.h"

enum Animals{
    LION,
    DOLPHIN,
};

class AnimalInformation: public Information{
    public:
    Animals type;
    AnimalInformation(std::string, int, Animals);
    //Other stuff that we may need to create an Animal object
};

#endif