#include "EnclosureInformation.h"

EnclosureInformation::EnclosureInformation(std::string name, int cost, EnclosureType type, float area, float volume, int maxAnimals) :  Information(name, cost), type(type), area(area), volume(volume), maxAnimals(maxAnimals){

}
