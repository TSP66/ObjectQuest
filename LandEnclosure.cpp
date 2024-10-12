#include "LandEnclosure.h"


//Default constructor for debugging purposes
LandEnclosure::LandEnclosure() : Enclosure("", 0, LAND) {

}

LandEnclosure::LandEnclosure(std::string name, int maxAnimals) : Enclosure(name, maxAnimals, LAND) {

}

