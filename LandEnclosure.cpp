#include "LandEnclosure.h"


LandEnclosure::LandEnclosure(float area, int maxAnimals) : Enclosure(maxAnimals), area(area){

}

float LandEnclosure::get_area(){
    return LandEnclosure::area;
}
void LandEnclosure::set_area(float area){
    LandEnclosure::area = area;
}
