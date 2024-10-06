#include "Tank.h"

//Blank Intialization for debugging purposes
Tank::Tank() : Enclosure(std::string(""), 0, AQUATIC){
    Tank::volume = 0;
}

Tank::Tank(std::string name, float volume, int maxAnimals) : Enclosure(name, maxAnimals, AQUATIC){
    Tank::volume = volume;
}