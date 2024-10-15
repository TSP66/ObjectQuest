#include "Enclosure.h"

//Function determines the current number of animals in each inclusure
// it takes all variables needed to defien the enclosure
Enclosure::Enclosure(std::string name, int maxAnimals, EnclosureType enclosureType) : maxAnimals(maxAnimals), name(name), enclosureType(enclosureType){
    Enclosure::currentAnimals = 0;
}

// returns ID of enclosure 
int Enclosure::get_id(void){
    return Enclosure::id;
}

//sets the ID of the enclosure
void Enclosure::set_id(int id){
     Enclosure::id=id;
}   
//returns the name of the enclosure 

std::string Enclosure::get_name(void){
     return Enclosure::name;
}
//function used to add animal to the endclosure 
//
bool Enclosure::addAnimal(int id, std::shared_ptr<Animal> animal){
    if  (Enclosure::currentAnimals < Enclosure::maxAnimals){
         Enclosure::currentAnimals++;
         Enclosure::animals[id] = animal;
         return true;
    } else {
         return false;
    }
}

//used to to remove animals 
//animals IDs are removed
//theoretically the animals die when this function is run 
bool Enclosure::removeAnimal(int id){
     Enclosure::animals.erase(id);
     Enclosure::currentAnimals--;
     return true; //Sucessfully remove it -need to do better checking in the future
}

//returns the current number of animals in the enclosure 
int Enclosure::get_currentAnimals(void){
     return Enclosure::currentAnimals;
}
//returns the maximum amount of animals that can exist 
//in any one enclosure at a time 
int Enclosure::get_maxAnimals(void){
      return Enclosure::maxAnimals;
}