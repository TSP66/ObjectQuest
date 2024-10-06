#include "EnclosureInformation.h"

EnclosureInformation::EnclosureInformation(std::string name, int cost, EnclosureType type, float area, float volume) :  Information(name, cost), type(type), area(area), volume(volume){

}
