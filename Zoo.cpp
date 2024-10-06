#include "Zoo.h"

Zoo::Zoo(){
    Zoo::enclosureInformation = Zoo::makeEnclosureInformation();
    Zoo::animalInformation = Zoo::makeAnimalInformation();
}

void Zoo::summary(std::string name){

    std::cout << "\n" << name << " zoo:\n";

    for (int enclosureId : Zoo::enclosureIds){

        std::cout << INDENT << "Enclosure (type: " << Zoo::enclosures[enclosureId]->get_name() 
                            << ", id: " << Zoo::enclosures[enclosureId]->get_id() << "):\n";
        
        bool empty = true;

        for (auto mapObject : Zoo::enclosures[enclosureId]->animals){
            std::cout << INDENT << INDENT << mapObject.second->get_name() //name
                      << " (age: " << mapObject.second->get_age() << ", id: " << mapObject.first << ")\n";
            empty = false;
        }
        if (empty)
             std::cout << INDENT << INDENT << "EMPTY\n";
    }
    std::cout << "\n";
}

int Zoo::buyAnimal(){

    Animal * newAnimal;

    int choice = Zoo::displayOptions(Zoo::animalInformation);
    AnimalInformation parameters = Zoo::animalInformation[choice];

    int id = (int) (std::rand()+1.0)*10000;
    id = abs(id);

    switch (parameters.type){
        case LION:
        newAnimal = new Lion(id);
        break;
        case DOLPHIN:
        newAnimal= new Dolphin(id);
        break;
    }

    int numEnclosures = Zoo::enclosureIds.size();

    if (numEnclosures < 1){
        std::cout << "You have no enclosures!\n";
        delete newAnimal; //Free memory if can't make it
        return 0;
    }

    bool suitableEnclosures = false;

    for (int i = 0; i < numEnclosures; i++){
        int id = Zoo::enclosureIds[i];
        if (Zoo::enclosures[id]->enclosureType == parameters.enclosureType){
            std::cout << INDENT << i << ": " << Zoo::enclosures[id]->get_name() << " | " << Zoo::enclosures[id]->get_id() << "\n";
            suitableEnclosures = true;
        }
    }

    if (!suitableEnclosures) {
        std::cout << "You have no suitable enclosures!\n";
        delete newAnimal; //Free memory if can't make it
        return 0;
    }

    int enclosureChoice = -1;

    std::cout << "Okay, which enclosure would you like to put it in: ";
    std::cin >> enclosureChoice;

    while ((enclosureChoice < 0) || (enclosureChoice >= numEnclosures)){
        std::cout << "Invalid input, try again: ";
        std::cin >> enclosureChoice;
    }

    //Create shared pointer
    std::shared_ptr<Animal> newAnimalPtr = std::shared_ptr<Animal>(std::move(newAnimal));

    //Add pointer to enclosure object
    if(!Zoo::enclosures[Zoo::enclosureIds[enclosureChoice]]->addAnimal(id, newAnimalPtr)){
        std::cout << "Enclosure has no space!\n";
        //delete newAnimalPtr; //Free memory if can't make it
        return 0;
    }

    //Add pointer to Zoo object
    Zoo::animals[id] = newAnimalPtr;
    Zoo::animalIds.push_back(id);

    return parameters.cost;
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
    int id = (int) (std::rand()+1.0)*10000;
    id = abs(id);

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
