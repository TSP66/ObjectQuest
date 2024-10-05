#include "Zoo.h"

Zoo::Zoo(){

}

void Zoo::addAnimal(std::shared_ptr<Animal> animal){
    Zoo::animals[animal->get_id()] = animal;
}

bool Zoo::buildEnclosure(void){
    
}

void Zoo::addEnclosure(EnclosureType enclosureType){

    Enclosure * newEnclosure;

    //std::cout << "What type of new enclosure"

    //Generate a new random id; Probably a better way to do this
    int id = (int) std::rand()*1000000;

    switch (enclosureType) {

        case LAND:
        newEnclosure = new LandEnclosure();
        break;

        case AQUATIC:
        newEnclosure = new Tank();
        break;
    }

    std::unique_ptr<Enclosure> newEnclosureUP = std::unique_ptr<Enclosure>(newEnclosure);

    newEnclosureUP->set_id(id);

    Zoo::enclosures[id] = std::move(newEnclosureUP);

    //return true; //Successfully created new Ensclosure

}



