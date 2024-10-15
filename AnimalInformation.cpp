#include "AnimalInformation.h"
// returns an animals information. This includes there name, 
//cost type, and enclosure type .
AnimalInformation::AnimalInformation(std::string name, int cost, Animals type, EnclosureType enclosureType) : Information(name, cost), type(type), enclosureType(enclosureType){
    
}
