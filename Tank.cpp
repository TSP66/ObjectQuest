#include "Tank.h"

//Blank Intialization for debugging purposes.
Tank::Tank() : Enclosure(std::string(""), 0, AQUATIC){
}

Tank::Tank(std::string name, int maxAnimals) : Enclosure(name, maxAnimals, AQUATIC){

}