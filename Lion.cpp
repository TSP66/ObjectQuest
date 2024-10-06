#include "Lion.h"

Lion::Lion(int id) : LandAnimal(id, "Lion"){

}
bool Lion::timestep(){
    return true;
}