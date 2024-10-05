#include "Tank.h"

//Blank Intialization for debugging purposes
Tank::Tank() : Enclosure(0){
    Tank::volume = 0;
}

Tank::Tank(float volume, int maxAnimals) : Enclosure(maxAnimals){
    Tank::volume = volume;
}