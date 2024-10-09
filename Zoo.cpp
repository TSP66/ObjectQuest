#include "Zoo.h"

Zoo::Zoo(){
    Zoo::enclosureInformation = Zoo::makeEnclosureInformation();
    Zoo::animalInformation = Zoo::makeAnimalInformation();
    Zoo::ticketPrice = 1;
}

void Zoo::summary(std::string name, int money, int day, DailySales dailySales){

    std::cout << "\n" << GREEN << name <<" zoo" << RESET << " (Day: " << day << ", Funds: $" << money << ", Visitors: " 
                      << dailySales.visitors << ", Sales: $" << dailySales.revenue <<")\n";

    bool zooEmpty = true;

    for (int enclosureId : Zoo::enclosureIds){

        std::cout << INDENT << MAGENTA << "Enclosure" << RESET <<" (type: " << Zoo::enclosures[enclosureId]->get_name() 
                            << ", id: " << Zoo::enclosures[enclosureId]->get_id() << "):\n";
        
        bool enclosureEmpty = true;

        for (auto mapObject : Zoo::enclosures[enclosureId]->animals){
            std::cout << INDENT << INDENT << CYAN << mapObject.second->get_name() << RESET //name
                      << " (age: " << (int) round(mapObject.second->get_age()) 
                      << ", sex: " << sexToString(mapObject.second->get_sex())
                      << ", happiness: " << mapObject.second->get_happiness()
                      << ", id: " << mapObject.first << ")\n";
    

            enclosureEmpty = false;
        }
        if (enclosureEmpty)
            std::cout << INDENT << INDENT << RED << "EMPTY\n" << RESET;
        
        zooEmpty = false;
    }
    if (zooEmpty) {
        std::cout << INDENT << RED << "EMPTY\n" << RESET;
    }
    std::cout << "\n";
}

DailySales Zoo::getRevenue(){

    double zooScore = 0;
    for (auto mapObject : Zoo::animals){

        double animalScore = pow((double) mapObject.second->get_cost()/25.0, 2.0); //Exotic Animals are more expensive but also more popular

        if (mapObject.second->get_age() < 1.0){
            animalScore *= 2.5; //People love baby animals
        }

        zooScore += animalScore;
    }

    double expodent = 1.0 / (1.0 + pow(1.005, zooScore));

    double weather_factor = ((double) rand())/((double) RAND_MAX);

    int visitors = (int) (250.0 + 750.0 * weather_factor) * exp(-expodent * (double) Zoo::ticketPrice) * (log10(zooScore+10.0)-1.0);

    return {visitors, visitors * Zoo::ticketPrice};

}

Changes Zoo::buyAnimal(int money){

    Animal * newAnimal;

    int choice = Zoo::displayOptions(Zoo::animalInformation);
    AnimalInformation parameters = Zoo::animalInformation[choice];

    if (parameters.cost > money){
        std::cout << RED << "Insufficient Funds!\n" << RESET;
        return {0};
    }

    const int id = abs((int) (std::rand()+1.0)*10000);

    switch (parameters.type){
        #define XX(NAME) case CAPITALIZE_ANIMAL(NAME): \
        newAnimal = new NAME(id); \
        break; 
        ANIMAL_LIST(XX)
        #undef XX
    }

    int numEnclosures = Zoo::enclosureIds.size();

    if (numEnclosures < 1){
        std::cout << RED << "You have no enclosures!\n" << RESET;
        delete newAnimal; //Free memory if can't make it
        return {0};
    }

    std::vector<int> suitableEnclosures;


    for (int i = 0; i < numEnclosures; i++){
        int id = Zoo::enclosureIds[i];
        if (Zoo::enclosures[id]->enclosureType == parameters.enclosureType){
            std::cout << INDENT << i << ": " << MAGENTA << Zoo::enclosures[id]->get_name() << RESET <<" | " << Zoo::enclosures[id]->get_id() << "\n";
            suitableEnclosures.push_back(i);
        }
    }

    if (suitableEnclosures.size() == 0) {
        std::cout << RED << "You have no suitable enclosures!\n" << RESET;
        delete newAnimal; //Free memory if can't make it
        return {0};
    }

    int enclosureChoice = -1;

    std::cout << "Okay, which enclosure would you like to put it in: ";
    std::cin >> enclosureChoice;

    while (std::find(suitableEnclosures.begin(), suitableEnclosures.end(), enclosureChoice) == suitableEnclosures.end()){
        std::cout << "Invalid input, try again: ";
        std::cin >> enclosureChoice;
    }

    //Create shared pointer
    std::shared_ptr<Animal> newAnimalPtr = std::shared_ptr<Animal>(std::move(newAnimal));

    //Add pointer to enclosure object
    if(!Zoo::enclosures[Zoo::enclosureIds[enclosureChoice]]->addAnimal(id, newAnimalPtr)){
        std::cout << RED << "Enclosure has no space!\n" << RESET;
        //delete newAnimalPtr; //Free memory if can't make it
        return {0};
    }

    //Add pointer to Zoo object
    newAnimalPtr->enclosureID = Zoo::enclosureIds[enclosureChoice];
    newAnimalPtr->set_cost(parameters.cost);
    Zoo::animals[id] = newAnimalPtr;
    Zoo::animalIds.push_back(id);

    return {parameters.cost};
}

Changes Zoo::buildEnclosure(int money){

    int choice = Zoo::displayOptions(Zoo::enclosureInformation);
    EnclosureInformation parameters = Zoo::enclosureInformation[choice];

    if (parameters.cost > money){
        std::cout << RED << "Insufficient Funds!\n" << RESET;
        return {0};
    }

    Zoo::addEnclosure(parameters);
    return {parameters.cost};

}

void Zoo::addEnclosure(EnclosureInformation parameters){

    Enclosure * newEnclosure;

    //std::cout << "What type of new enclosure"

    //Generate a new random id; Probably a better way to do this
    const int id = abs((int) (std::rand()+1.0)*10000);

    switch (parameters.type) {

        case LAND:
        newEnclosure = new LandEnclosure(parameters.name, parameters.area, parameters.maxAnimals);
        break;

        case AQUATIC:
        newEnclosure = new Tank(parameters.name, parameters.volume, parameters.maxAnimals);
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
        EnclosureInformation("Big Enclosure", 5000, LAND, 0, 100, 10),
        EnclosureInformation("Medium Enclosure", 2000, LAND, 0, 30, 3),
        EnclosureInformation("Small Enclosure", 1000, LAND, 0, 10, 2),
        EnclosureInformation("Big Tank", 5000, AQUATIC, 10, 0, 10),
        EnclosureInformation("Medium Tank", 2000, AQUATIC, 3, 0, 3),
        EnclosureInformation("Small Tank", 1000, AQUATIC, 1, 0, 2),
    };
    return enclosureInformation;
}

std::vector<AnimalInformation> Zoo::makeAnimalInformation(){
    std::vector<AnimalInformation> animalInformation{
        #define XX(NAME) AnimalInformation(#NAME, PRICE_ANIMAL(NAME), CAPITALIZE_ANIMAL(NAME), LAND),
        LAND_ANIMAL_LIST(XX)
        #undef XX
        #define XX(NAME) AnimalInformation(#NAME, PRICE_ANIMAL(NAME), CAPITALIZE_ANIMAL(NAME), AQUATIC),
        AQUATIC_ANIMAL_LIST(XX)
        #undef XX
    };
    return animalInformation;
}

template int Zoo::displayOptions<EnclosureInformation>(std::vector<EnclosureInformation>);
template int Zoo::displayOptions<AnimalInformation>(std::vector<AnimalInformation>);
template int Zoo::displayOptions<UtilitiesInformation>(std::vector<UtilitiesInformation>);

Changes Zoo::setTicketPrice(){
    std::cout << "Your current ticket price is $" << Zoo::ticketPrice << ", changing it will cost $100\nNew price (ENTER to keep old): ";
    int newTicketPrice = Zoo::ticketPrice;
    std::cin >> newTicketPrice;
    while (newTicketPrice <= 0){
        std::cout << "Invalid ticket price, enter again: ";
        std::cin >> newTicketPrice;
    }
    if (newTicketPrice == Zoo::ticketPrice)
        return {0};
    else {
        Zoo::ticketPrice = newTicketPrice;
        return {100};
    }

}

void Zoo::deleteAnimal(int id){
    //Delete the id of the dead animal from the ID vector

    auto it = std::find(Zoo::animalIds.begin(), Zoo::animalIds.end(), id);

    if (it != Zoo::animalIds.end()) {
        Zoo::animalIds.erase(it);
    }
    //Delete the animal from the Zoo and its Enclosure
    int enclosureID = Zoo::animals.at(id)->enclosureID; //Get ID of enclosure

    Zoo::animals.erase(id); //From Zoo
    Zoo::enclosures.at(enclosureID)->removeAnimal(id); //From Enclosure

}

void Zoo::ageAnimals(){

    std::vector<int> deleteIds;

    for (auto mapObject : Zoo::animals){
        int Id = mapObject.first;
        Death death = mapObject.second->timestep();
        if(death != NONE){
            std::cout << RED << "† A " << mapObject.second->get_name() << RESET << " has died (Age: " << (int) round(mapObject.second->get_age()) 
                      << ", cause: " << deathToString(death)
                      << ", id: " << Id << ")\n";
            deleteIds.push_back(Id);
        }
    }

    for (int id : deleteIds){
        deleteAnimal(id);
    }
}

Changes Zoo::feedAnimal(int money){

    std::cout << "Which Animal would you like to feed:\n";
    int numAnimals = Zoo::animalIds.size();

    for (int i = 0; i < numAnimals; i++){
        int Id = Zoo::animalIds[i];
    
        std::cout << INDENT << i << ": " << BLUE << Zoo::animals[Id]->get_name() << RESET //name
                      << " (cost to feed: $" << (int) round(Zoo::animals[Id]->get_hunger()/3.0 * Zoo::animals[Id]->get_cost()/10.0)
                      << ", hunger: " << Zoo::animals[Id]->get_hunger() 
                      << ", happiness: " << Zoo::animals[Id]->get_happiness()
                      << ", id: " << Id << ")\n";
    }

    std::cout << "Choice: ";
    int choice;
    std::cin >> choice;

    while ((choice < 0) || (choice >= numAnimals)){
        std::cout << RED << "Invalid, please select one of the above animals: " << RESET;
        std::cin >> choice;
    }

    int Id = Zoo::animalIds[choice];
    int cost = (int) round(Zoo::animals[Id]->get_hunger()/10.0 * Zoo::animals[Id]->get_cost()/10.0);

    if (cost > money){
        std::cout << RED << "Insufficient funds!\n" << RESET;
        return {0};
    }
    
    Zoo::animals[Id]->set_happiness(Zoo::animals[Id]->get_happiness() + 100.0); //Increase happiness by 100
    Zoo::animals[Id]->set_hunger(0); //Set hunger to zero

    return {cost};

}

Changes Zoo::sellAnimal(void){

    std::cout << "Which Animal would you like to sell:\n";

    int numAnimals = Zoo::animalIds.size();

    for (int i = 0; i < numAnimals; i++){
        int Id = Zoo::animalIds[i];
    
        std::cout << INDENT << i << ": " << BLUE << Zoo::animals[Id]->get_name() << RESET//name
                      << " (value: $" << (int) std::max(1.0, Zoo::animals[Id]->get_cost() - 3.0 * Zoo::animals[Id]->get_age())
                      << ", id: " << Id << ")\n";
    }

    std::cout << "Choice: ";
    int choice;
    std::cin >> choice;

    while ((choice < 0) || (choice >= numAnimals)){
        std::cout << "Invalid, please select one of the above animals: ";
        std::cin >> choice;
    }

    int Id = Zoo::animalIds[choice];
    int value = (int) std::max(1.0, Zoo::animals[Id]->get_cost() - 3.0 * Zoo::animals[Id]->get_age());

    Zoo::deleteAnimal(Id);

    return {-value}; //Negative as the user get to keep the value
}

Changes Zoo::moveAnimal(void){

    std::cout << "Which Animal would you like to move:\n";

    int numAnimals = Zoo::animalIds.size();

    for (int i = 0; i < numAnimals; i++){
        int Id = Zoo::animalIds[i];
    
        std::cout << INDENT << i << ": " << BLUE << Zoo::animals[Id]->get_name() << RESET//name
                      << " (sex: " << sexToString(Zoo::animals[Id]->get_sex())
                      << ", age: " << (int) round(Zoo::animals[Id]->get_age())
                      << ", id: " << Id << ")\n";
    }

    std::cout << "Choice: ";
    int choice;
    std::cin >> choice;

    while ((choice < 0) || (choice >= numAnimals)){
        std::cout << "Invalid, please select one of the above animals: ";
        std::cin >> choice;
    }

    int animalId = Zoo::animalIds[choice];
    int oldEnclosureId = Zoo::animals.at(animalId)->enclosureID;

    std::vector<int> suitableEnclosures;

    for (int i = 0; i < Zoo::enclosureIds.size(); i++){
        int id = Zoo::enclosureIds[i];
        if (Zoo::enclosures[id]->enclosureType == Zoo::enclosures[oldEnclosureId]->enclosureType){
            std::cout << INDENT << i << ": " << MAGENTA << Zoo::enclosures[id]->get_name() << RESET << " | " << Zoo::enclosures[id]->get_id() << "\n";
            suitableEnclosures.push_back(i);
        }
    }

    if (suitableEnclosures.size() <= 1) {
        std::cout << RED << "You have no other suitable enclosures!\n" << RESET;
        return {0};
    }

    int enclosureChoice = -1;

    std::cout << "Okay, which enclosure would you like to put it in: ";
    std::cin >> enclosureChoice;

    while (std::find(suitableEnclosures.begin(), suitableEnclosures.end(), enclosureChoice) == suitableEnclosures.end()){
        std::cout << RED << "Invalid input, try again: " << RESET;
        std::cin >> enclosureChoice;
    }

    if(!Zoo::enclosures[Zoo::enclosureIds[enclosureChoice]]->addAnimal(animalId, Zoo::animals.at(animalId))){
        std::cout << RED << "Enclosure has no space!\n" << RESET;
        //delete newAnimalPtr; //Free memory if can't make it
        return {0};
    }

    Zoo::animals.at(animalId)->enclosureID = Zoo::enclosureIds[enclosureChoice];
    Zoo::enclosures.at(oldEnclosureId)->removeAnimal(animalId);

    return {0};
}

Changes Zoo::breadAnimals(int money){

    if (money < 10) {
        std::cout << RED << "Insufficient funds to breed!\n" << RESET;
    } 

    std::cout << "Which Animals would you like to breed (cost $10):\n";

    int numAnimals = Zoo::animalIds.size();

    for (int i = 0; i < numAnimals; i++){
        int Id = Zoo::animalIds[i];
    
        std::cout << INDENT << i << ": " << BLUE << Zoo::animals[Id]->get_name() << RESET //name
                      << " (sex: " << sexToString(Zoo::animals[Id]->get_sex())
                      << ", age: " << (int) round(Zoo::animals[Id]->get_age())
                      << ", id: " << Id << ")\n";
    }

    std::cout << "Choice 1: ";
    int choice1;
    std::cin >> choice1;

    while ((choice1 < 0) || (choice1 >= numAnimals)){
        std::cout << RED << "Invalid, please select one of the above animals: " << RESET;
        std::cin >> choice1;
    }

    std::cout << "Choice 2: ";
    int choice2;
    std::cin >> choice2;

    while ((choice2 < 0) || (choice2 >= numAnimals) || (choice1 == choice2)){
        std::cout << RED << "Invalid, please select one of the above animals: " << RESET;
        std::cin >> choice2;
    }

    int animal1Id = Zoo::animalIds[choice1];
    int animal2Id = Zoo::animalIds[choice2];

    if (Zoo::animals.at(animal1Id)->enclosureID != Zoo::animals.at(animal2Id)->enclosureID){
        std::cout << RED << "Animals must be from the same enclosure!\n" << RESET;
        return {0};
    }

    int enclosureID = Zoo::animals.at(animal1Id)->enclosureID;

    if (Zoo::animals.at(animal1Id)->get_name() != Zoo::animals.at(animal2Id)->get_name()){
        std::cout << RED << "Animals must be the same species!\n" << RESET;
        return {0};
    }

    if ((Zoo::animals.at(animal1Id)->get_sex() != Zoo::animals.at(animal1Id)->get_sex())) {
        std::cout << RED << "Animals must be of different sexes!\n" << RESET;
        return {0};
    }

    if (Zoo::enclosures.at(enclosureID)->get_currentAnimals() >= Zoo::enclosures.at(enclosureID)->get_maxAnimals()){
        std::cout << RED << "No room left in enclosure!\n" << RESET;
        return {0};
    }

    if ((round(Zoo::animals.at(animal1Id)->get_age()) < 1.0) || (round(Zoo::animals.at(animal1Id)->get_age()) < 1.0)) {
        std::cout << RED << "Animals must be of sexual maturity!\n" << RESET;
        return {0};
    }

    bool success_rate = rand()>RAND_MAX/2;
    if (success_rate){
    std::cout << GREEN << "All conditions meet.... Attempting to breed animals...\nSuccess!\n" << RESET;
    }

    else {
    std::cout << RED << "All conditions meet.... Attempting to breed animals...\nBreeding attempt failed!\n" << RESET;
    return{0};
    }
    
    Animal * newAnimal;

    int id = rand();

    Animals type = mapStringToAnimal(Zoo::animals.at(animal1Id)->get_name());

    switch (type){
        #define XX(NAME) case CAPITALIZE_ANIMAL(NAME): \
        newAnimal = new NAME(id); \
        break; 
        ANIMAL_LIST(XX)
        #undef XX
    }

    std::shared_ptr<Animal> newAnimalPtr = std::shared_ptr<Animal>(std::move(newAnimal));

    //Add pointer to Zoo object
    newAnimalPtr->enclosureID = enclosureID;
    Zoo::enclosures[enclosureID]->addAnimal(id, newAnimalPtr);
    newAnimalPtr->set_cost(animalToPrice(type));
    Zoo::animals[id] = newAnimalPtr;
    Zoo::animalIds.push_back(id);

    return {10};
}

Changes Zoo :: buildUtilities(int){
    std::cout << "Which utility do you wish to purchase" << "\n" ;\
    int choice = displayOptions(makeUtilitiesInformation());
}

std::vector<UtilitiesInformation> Zoo :: makeUtilitiesInformation(){
    std::vector<UtilitiesInformation> enclosureInformation{
        UtilitiesInformation("Toilet", 100, 1000, TOILET),
        UtilitiesInformation("Fountain", 50, 500, FOUNTAIN),
        UtilitiesInformation("Gift Shop", 400, 3000, GIFTSHOP),
    };
    return enclosureInformation;
}