#include "Zoo.h"

Zoo::Zoo(){
    Zoo::enclosureInformation = Zoo::makeEnclosureInformation();
    Zoo::animalInformation = Zoo::makeAnimalInformation();
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

template <typename T> int Zoo::displayOptions(std::vector<T> options){
    int option = -1;
    for (int i = 0; i < (int) options.size(); i++) {
        std::cout << INDENT << i << ": " << options[i].name << " $" << options[i].cost << "\n";
    }
    std::cout << "Your choice: ";
    std::cin >> option;
    return option;
}


std::vector<EnclosureInformation> Zoo::makeEnclosureInformation(){
    std::vector<EnclosureInformation> enclosureInformation{
        EnclosureInformation("Big Enclosure", 5000, LAND, 0, 100),
        EnclosureInformation("Medium Enclosure", 2000, LAND, 0, 30),
        EnclosureInformation("Small Enclosure", 1000, LAND, 0, 10),
        EnclosureInformation("Big Tank", 5000, AQUATIC, 10, 0),
        EnclosureInformation("Medium Tank", 2000, AQUATIC, 3, 0),
        EnclosureInformation("Small Tank", 1000, AQUATIC, 1, 0),
    };
    return enclosureInformation;
}

std::vector<AnimalInformation> Zoo::makeAnimalInformation(){
    std::vector<AnimalInformation> animalInformation{
        AnimalInformation("Lion", 30, LION),
        AnimalInformation("Dolphin", 10, DOLPHIN),
    };
    return animalInformation;
}

template int Zoo::displayOptions<EnclosureInformation>(std::vector<EnclosureInformation>);
template int Zoo::displayOptions<AnimalInformation>(std::vector<AnimalInformation>);
