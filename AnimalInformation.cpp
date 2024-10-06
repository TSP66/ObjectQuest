#include "AnimalInformation.h"

AnimalInformation::AnimalInformation(std::string name, int cost, Animals type, EnclosureType enclosureType) : Information(name, cost), type(type), enclosureType(enclosureType){
    
}