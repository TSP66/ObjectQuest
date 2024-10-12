#include "EnclosureInformation.h"

EnclosureInformation::EnclosureInformation(std::string name, int cost, EnclosureType type, int maxAnimals) :  Information(name, cost), type(type), maxAnimals(maxAnimals){

}
