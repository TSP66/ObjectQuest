#include "Dolphin.h"

Dolphin::Dolphin(int id) : AquaticAnimal(id, "Dolpin") {

}

bool Dolphin::timestep(){
    return true;
}