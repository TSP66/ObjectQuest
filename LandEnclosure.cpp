#include "LandEnclosure.h"


//Default constructor for debugging purposes
LandEnclosure::LandEnclosure() : Enclosure("", 0, LAND), area(0) {

}

LandEnclosure::LandEnclosure(std::string name, float area, int maxAnimals) : Enclosure(name, maxAnimals, LAND), area(area){

}

float LandEnclosure::get_area(){
    return LandEnclosure::area;
}
void LandEnclosure::set_area(float area){
    LandEnclosure::area = area;
}
