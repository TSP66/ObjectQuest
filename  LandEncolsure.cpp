#include "LandEncolsure.h"


LandEncolsure::LandEncolsure(float area, int maxAnimals) : area(area), Encolsure(maxAnimals){

}

float LandEncolsure::get_area(){
    return LandEncolsure::area;
}
void LandEncolsure::set_area(float area){
    LandEncolsure::area = area;
}
