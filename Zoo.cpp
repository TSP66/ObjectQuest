#include "Zoo.h"

Zoo::Zoo(){
    Zoo::enclosureInformation = Zoo::makeEnclosureInformation();
    Zoo::animalInformation = Zoo::makeAnimalInformation();
} 

int Zoo::buyAnimal(){

    Animal * newAnimal;

    int choice = Zoo::displayOptions(Zoo::animalInformation);
    AnimalInformation parameters = Zoo::animalInformation[choice];
    int id = (int) std::rand()*1000000;

    int numEnclosures = Zoo::enclosureIds.size();

    if (numEnclosures < 1){
        std::cout << "You have no enclosures!";
        return 0;
    }

    std::cout << "Okay, which enclosure would you like to put it in: ";

    for (int i = 0; i < numEnclosures; i++){
        Zoo::enclosures[i]->get_name();
    }

    //Zoo::animals[id] = animal;
    Zoo::animalIds.push_back(id);
}

int Zoo::buildEnclosure(void){

    int choice = Zoo::displayOptions(Zoo::enclosureInformation);
    EnclosureInformation parameters = Zoo::enclosureInformation[choice];
    Zoo::addEnclosure(parameters);
    return parameters.cost;

}

void Zoo::addEnclosure(EnclosureInformation parameters){

    Enclosure * newEnclosure;

    //std::cout << "What type of new enclosure"

    //Generate a new random id; Probably a better way to do this
    int id = (int) std::rand()*1000000;

    switch (parameters.type) {

        case LAND:
        newEnclosure = new LandEnclosure(parameters.name, parameters.area, 5);
        break;

        case AQUATIC:
        newEnclosure = new Tank(parameters.name, parameters.volume, 5);
        break;
    }

    std::unique_ptr<Enclosure> newEnclosureUP = std::unique_ptr<Enclosure>(newEnclosure);

    newEnclosureUP->set_id(id);

    Zoo::enclosures[id] = std::move(newEnclosureUP);

    Zoo::enclosureIds.push_back(id);

    //return true; //Successfully created new Ensclosure

}

template <typename T> int Zoo::displayOptions(std::vector<T> options){
    int option = -1;
    int numberOptions = (int) options.size();
    for (int i = 0; i < numberOptions; i++) {
        std::cout << INDENT << i << ": " << options[i].name << " | $" << options[i].cost << "\n";
    }
    std::cout << "Your choice: ";
    std::cin >> option;
    if ((option < 0) || (option >= numberOptions)){
        std::cout << "Invalid Option\n";
        Zoo::displayOptions(options);
    }
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
        AnimalInformation("Lion", 30, LION, LAND),
        AnimalInformation("Dolphin", 10, DOLPHIN, AQUATIC),
    };
    return animalInformation;
}

template int Zoo::displayOptions<EnclosureInformation>(std::vector<EnclosureInformation>);
template int Zoo::displayOptions<AnimalInformation>(std::vector<AnimalInformation>);
