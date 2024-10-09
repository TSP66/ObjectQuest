#include "UtilitiesInformation.h"
#include <iostream>

UtilitiesInformation :: UtilitiesInformation(std::string name, int revenue, int cost, UtilityType type) : Information(name, cost), revenue(revenue), type(type){
}
