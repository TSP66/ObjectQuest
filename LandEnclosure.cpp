#include "LandEnclosure.h"


//Default constructor for debugging purposes
LandEnclosure::LandEnclosure() : Enclosure(0), area(0) {

}

LandEnclosure::LandEnclosure(float area, int maxAnimals) : Enclosure(maxAnimals), area(area){

}

float LandEnclosure::get_area(){
    return LandEnclosure::area;
}
void LandEnclosure::set_area(float area){
    LandEnclosure::area = area;
}
