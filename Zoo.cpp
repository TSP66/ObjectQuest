#include "Zoo.h"

Zoo::Zoo(){
    Zoo::enclosureInformation = Zoo::makeEnclosureInformation();
    Zoo::animalInformation = Zoo::makeAnimalInformation();
    Zoo::utilitiesInformation = Zoo::makeUtilitiesInformation();
    Zoo::ticketPrice = 1; //ticket price initially set to 1. 
    //maining every costomer pays 1 dollar for entry 

    //ticket price options
    //setting ticket prices affects costomer quantity 
    Zoo::ticketPriceChoices = {
        "$1",
        "$2",
        "$5",
        "$10",
        "$20",
        "$50",
        "$100",
    };

}


std::string Zoo::summary(std::string name, int money, int day, DailySales dailySales){

    std::string message = "\n" + GREEN + name +" zoo" + RESET + " (Day: " + std::to_string(day) + ", Funds: $" + std::to_string(money) + ", Visitors: "
                      + std::to_string(dailySales.visitors) + ", Sales: $" + std::to_string(dailySales.revenue) 
                      + ", Debt: $" + std::to_string(Zoo::bank.getTotal()) +")\n";


    bool zooEmpty = true;

    for (int enclosureId : Zoo::enclosureIds){

        message += INDENT + MAGENTA + "Enclosure" + RESET +" (type: " + Zoo::enclosures[enclosureId]->get_name()
                            + ", id: " + std::to_string(Zoo::enclosures[enclosureId]->get_id()) + "):\n";


        bool enclosureEmpty = true;

        for (auto mapObject : Zoo::enclosures[enclosureId]->animals){

            message += INDENT + INDENT + CYAN + mapObject.second->get_name() + RESET //name
                      + " (age: " + std::to_string((int) round(mapObject.second->get_age())) 
                      + ", sex: " + sexToString(mapObject.second->get_sex())
                      + ", happiness: " + std::to_string((int) round(mapObject.second->get_happiness()))
                      + ", id: " + std::to_string(mapObject.first) + ")\n";

            enclosureEmpty = false;
        }
        if (enclosureEmpty)
            message += INDENT + INDENT + RED + "EMPTY\n" + RESET;
        
        zooEmpty = false;
    }
    if (zooEmpty) {
        message += INDENT + INDENT + RED + "EMPTY\n" + RESET;
    }
    //std::cout << "\n";.
    message += "\n";
    return message;
}

DailySales Zoo::getRevenue(){

    double zooScore = 0;
    for (auto mapObject : Zoo::animals){

        double animalScore = pow((double) mapObject.second->get_cost()/25.0, 2.0); //Exotic Animals are more expensive but also more popular.

        if (mapObject.second->get_age() < 1.0){ //checks to see if animal is baby and if so acounts for that with revenue 
            animalScore *= 2.5; //People love baby animals.
        }

        zooScore += animalScore;
    }

    double expodent = 1.0 / (1.0 + pow(1.005, zooScore));
    //weather effects amount of visitors that visit zoo
    double weather_factor = ((double) rand())/((double) RAND_MAX);
    //visitors is used to determine the amount of revenue the zoo makes per turn (week)
    int visitors = (int) (250.0 + 750.0 * weather_factor) * exp(-expodent * (double) Zoo::ticketPrice) * (log10(zooScore+10.0)-1.0);

    return {visitors, visitors * Zoo::ticketPrice};

}

Changes Zoo::buyAnimal(int money){

    Animal * newAnimal;

    int choice = Zoo::displayOptions(Zoo::animalInformation); // displayes animal options e.g lion and dolphin
    AnimalInformation parameters = Zoo::animalInformation[choice];

    if (parameters.cost > money){ // if you dont have enough money "Insufficent funds will be displayed"
        return {0, true, std::string("Insufficient Funds!"), RED};
    }

    const int id = abs((int) (std::rand()+1.0)*10000);

    switch (parameters.type){
        #define XX(NAME) case CAPITALIZE_ANIMAL(NAME): \
        newAnimal = new NAME(id); \
        break; 
        ANIMAL_LIST(XX)
        #undef XX
    }

    int numEnclosures = Zoo::enclosureIds.size(); //determins the number of enclosures

    if (numEnclosures < 1){
        //std::cout << RED << "You have no enclosures!\n" << RESET.
        delete newAnimal; //Free memory if can't make it.
        return {0, true, std::string("You have no enclosures!"), RED};
    }

    std::vector<int> suitableEnclosures;
    std::vector<std::string> enclosureNames;

    for (int i = 0; i < numEnclosures; i++){
        int id = Zoo::enclosureIds[i];
        if (Zoo::enclosures[id]->enclosureType == parameters.enclosureType){
            //std::cout << INDENT << i << ": " << MAGENTA << Zoo::enclosures[id]->get_name() << RESET <<" | " << Zoo::enclosures[id]->get_id() << "\n";.
            enclosureNames.push_back(Zoo::enclosures[id]->get_name() + " | " + std::to_string(Zoo::enclosures[id]->get_id()));
            suitableEnclosures.push_back(i);
        }
    }

    if (suitableEnclosures.size() == 0) {
        //std::cout << RED << "You have no suitable enclosures!\n" << RESET;.
        delete newAnimal; //Free memory if can't make it.
        return {0, true, std::string("You have no suitable enclosures!"), RED};
    }

    int selection = optionSelector(enclosureNames, std::string("Okay, which enclosure would you like to put it in: "), true);
    int enclosureChoice = suitableEnclosures[selection];
    //Create shared pointer.
    std::shared_ptr<Animal> newAnimalPtr = std::shared_ptr<Animal>(std::move(newAnimal));

    //Add pointer to enclosure object.
    if(!Zoo::enclosures[Zoo::enclosureIds[enclosureChoice]]->addAnimal(id, newAnimalPtr)){
        return {0, true, std::string("Enclosure has no space!"), RED};
    }

    //Add pointer to Zoo object.
    newAnimalPtr->enclosureID = Zoo::enclosureIds[enclosureChoice];
    newAnimalPtr->set_cost(parameters.cost);
    Zoo::animals[id] = newAnimalPtr;
    Zoo::animalIds.push_back(id);

    return {parameters.cost, true, std::string("Successfully added animal to enclosure!"), GREEN};
}

Changes Zoo::buildEnclosure(int money){ //displays the enclosure information and allows user to opick which 
//enclosure they intend to build 

    int choice = Zoo::displayOptions(Zoo::enclosureInformation);
    EnclosureInformation parameters = Zoo::enclosureInformation[choice];

    if (parameters.cost > money){
        //std::cout << RED << "Insufficient Funds!\n" << RESET;.
        return {0, true, std::string("Insufficient Funds!"), RED};
    }

    Zoo::addEnclosure(parameters); // if enclosure is added successfully 
    return {parameters.cost, true, std::string("Successfully added enclosure!"), GREEN};
}

void Zoo::addEnclosure(EnclosureInformation parameters){

    Enclosure * newEnclosure;

    //std::cout << "What type of new enclosure".

    //Generate a new random id; Probably a better way to do this.
    const int id = abs((int) (std::rand()+1.0)*10000);

    switch (parameters.type) {

        case LAND: //creates a different enclosure depending on the enclosure type 
        newEnclosure = new LandEnclosure(parameters.name, parameters.maxAnimals); //land
        break;

        case AQUATIC:
        newEnclosure = new Tank(parameters.name, parameters.maxAnimals); //aquatic 
        break;
    }

    std::unique_ptr<Enclosure> newEnclosureUP = std::unique_ptr<Enclosure>(newEnclosure);

    newEnclosureUP->set_id(id);

    Zoo::enclosures[id] = std::move(newEnclosureUP);

    Zoo::enclosureIds.push_back(id);

    //return true; //Successfully created new Ensclosure

}

template <typename T> int Zoo::displayOptions(std::vector<T> options){
//displayes the users choices such as feed animals and breed animals 
    int numberOptions = (int) options.size();
    std::vector <std::string> choices;

    for (int i = 0; i < numberOptions; i++) {
        choices.push_back(options[i].name + " | $" + std::to_string(options[i].cost));
    }
    
    return optionSelector(choices);
}

//different enclosure sizes
//prices vary depedning on enclosure
//different sizes generate differetn revenue 
//
std::vector<EnclosureInformation> Zoo::makeEnclosureInformation(){
    std::vector<EnclosureInformation> enclosureInformation{
        EnclosureInformation("Big Enclosure", 5000, LAND, 10),
        EnclosureInformation("Medium Enclosure", 2000, LAND, 3),
        EnclosureInformation("Small Enclosure", 1000, LAND, 2),
        EnclosureInformation("Big Tank", 5000, AQUATIC, 10),
        EnclosureInformation("Medium Tank", 2000, AQUATIC, 3),
        EnclosureInformation("Small Tank", 1000, AQUATIC, 2),
    };
    return enclosureInformation;
}
//different utilitie options
//different utilities generate differnt revenue 
//and cost differnt amoutnts of money
std::vector<UtilitiesInformation> Zoo::makeUtilitiesInformation(){
    std::vector<UtilitiesInformation> enclosureInformation{
        UtilitiesInformation("Toilet", 100, 1000, TOILET),
        UtilitiesInformation("Fountain", 50, 600, FOUNTAIN),
        UtilitiesInformation("Gift Shop", 400, 3000, GIFTSHOP),
    };
    return enclosureInformation;
}

//diasplays animal information such as price and name and what enclosure type they require. 
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

int Zoo::ticketPriceFromOption(int option){
    return atoi(Zoo::ticketPriceChoices[option].substr(1, Zoo::ticketPriceChoices.size()-1).c_str());
}

Changes Zoo::setTicketPrice(){
//returns users current ticket price 
//further allows the user to change the ticket price for a fee
    std::cout << "Your current ticket price is $" << Zoo::ticketPrice << ", changing it will cost $100\nNew price (ENTER to keep old): ";

//allows the user to enter a ticket price of their choice 
//this changes customer appearances depending on if the ticket is of a fair price 
    int choice = optionSelector(Zoo::ticketPriceChoices, std::string("Enter a new ticket price: "), true);

    int newTicketPrice = ticketPriceFromOption(choice);

    if (newTicketPrice == Zoo::ticketPrice) //if ticket price isnt changed 
        return {0, true, std::string("No change in ticket price!"), GREEN};
    else {
        Zoo::ticketPrice = newTicketPrice; //displayed when ticket is successfully changed
        return {100, true, std::string("Successfully changed ticket price!"), GREEN};
    }

}

void Zoo::deleteAnimal(int id){
    //Delete the id of the dead animal from the ID vector.

    auto it = std::find(Zoo::animalIds.begin(), Zoo::animalIds.end(), id);

    if (it != Zoo::animalIds.end()) {
        Zoo::animalIds.erase(it);
    }
    //Delete the animal from the Zoo and its Enclosure.
    int enclosureID = Zoo::animals.at(id)->enclosureID; //Get ID of enclosure.

    Zoo::animals.erase(id); //From Zoo.
    Zoo::enclosures.at(enclosureID)->removeAnimal(id); //From Enclosure.

}

//how animals age using type step::
std::string Zoo::ageAnimals(){

    std::vector<int> deleteIds;

    std::string message = "";

    for (auto mapObject : Zoo::animals){
        int Id = mapObject.first;
        Death death = mapObject.second->timestep();
        if(death != NONE){ //what is displayed when an animal dies 
            message += RED + "† A " + mapObject.second->get_name() + RESET + " has died (Age: " + std::to_string((int) round(mapObject.second->get_age())) 
                      + ", cause: " + deathToString(death) //displays the cause of death
                      + ", id: " + std::to_string(Id) + ")\n";

            deleteIds.push_back(Id);
        }
    }

    for (int id : deleteIds){
        deleteAnimal(id); //deletes animal ID to free up sapce for a new animal 
    }

    return message;
}

Changes Zoo::feedAnimal(int money){ //feeding animals 

    int numAnimals = Zoo::animalIds.size();

    if (numAnimals == 0){
        return {0, true, std::string("You have no animals!"), RED}; // if you try to feed an animal without any animals bought
    }

    std::cout << "Which Animal would you like to feed:\n"; //allows the user t opick which animal they want to feed

    std::vector<std::string> animalsToFeed;

    for (int i = 0; i < numAnimals; i++){
        int Id = Zoo::animalIds[i];

        animalsToFeed.push_back(Zoo::animals[Id]->get_name() 
                                + "(cost to feed: $" + std::to_string(round(Zoo::animals[Id]->get_hunger()/3.0 * Zoo::animals[Id]->get_cost()/10.0)) 
                                + ", hunger: " + std::to_string(Zoo::animals[Id]->get_hunger()) 
                                + ", happiness: " + std::to_string(Zoo::animals[Id]->get_happiness())
                                + ", id: " + std::to_string(Id));
    }

    int choice = optionSelector(animalsToFeed, std::string("Which Animal would you like to feed: "), true);

    int Id = Zoo::animalIds[choice];
    int cost = (int) round(Zoo::animals[Id]->get_hunger()/10.0 * Zoo::animals[Id]->get_cost()/10.0);

    if (cost > money){
        //std::cout << RED << "Insufficient funds!\n" << RESET;.
        return {0, true, std::string("Insufficient funds!"), RED};
    }
    
    Zoo::animals[Id]->set_happiness(Zoo::animals[Id]->get_happiness() + 100.0); //Increase happiness by 100.
    Zoo::animals[Id]->set_hunger(0); //Set hunger to zero.

    return {cost, true, std::string("Successfully fed animal!"), GREEN};

}

Changes Zoo::sellAnimal(void){ //function used to sell animals 

    //std::cout << "Which Animal would you like to sell:\n";.

    int numAnimals = Zoo::animalIds.size();

    if (numAnimals == 0){
        return {0, true, std::string("You have no animals!"), RED}; //used if you try to sell animals without any present in the zoo
    }

    std::vector<std::string> animalsToSell;

    for (int i = 0; i < numAnimals; i++){
        int Id = Zoo::animalIds[i];

        animalsToSell.push_back(Zoo::animals[Id]->get_name() //shoes the value of the animal that your trying to sell and the animasl ID 
                                + "(value: $" + std::to_string(std::max(1.0, Zoo::animals[Id]->get_cost() - 3.0 * Zoo::animals[Id]->get_age()))
                                + ", id: " + std::to_string(Id));
    
    }

    int choice = optionSelector(animalsToSell, std::string("Which Animal would you like to sell: "), true); //allows the user to choose which animals to sell

    int Id = Zoo::animalIds[choice];
    int value = (int) std::max(1.0, Zoo::animals[Id]->get_cost() - 3.0 * Zoo::animals[Id]->get_age());

    Zoo::deleteAnimal(Id);//deletes the animals ID
    // frees up space for new animal once sold 
    return {-value}; //Negative as the user get to keep the value.
}

Changes Zoo::moveAnimal(void){

    int numAnimals = Zoo::animalIds.size();

    if (numAnimals == 0){
        return {0, true, std::string("You have no animals!"), RED}; //displays when you try to move an animal when no animals are in the zoo
    }

// asks the user which animal they wish to move. This only occurs when there are animals that 
//exist within the zoo 
    std::cout << "Which Animal would you like to move:\n";

    std::vector<std::string> animalsToMove;

    for (int i = 0; i < numAnimals; i++){
        int Id = Zoo::animalIds[i];
//user choosing animal from determining its sex age and ID
        animalsToMove.push_back(Zoo::animals[Id]->get_name() 
                                + "(sex: " + sexToString(Zoo::animals[Id]->get_sex())
                                + ", age: " + std::to_string(round(Zoo::animals[Id]->get_age()))
                                + ", id: " + std::to_string(Id));
    
        /*.
        std::cout << INDENT << i << ": " << BLUE << Zoo::animals[Id]->get_name() << RESET//name.
                      << " (sex: " << sexToString(Zoo::animals[Id]->get_sex()).
                      << ", age: " << (int) round(Zoo::animals[Id]->get_age()).
                      << ", id: " << Id << ")\n";.
        */
    }
//displays the output for the user to determine which animal he wants to move 
    int choice = optionSelector(animalsToMove, std::string("Which Animal would you like to move: "), true);
//
    int animalId = Zoo::animalIds[choice];
    int oldEnclosureId = Zoo::animals.at(animalId)->enclosureID;

    std::vector<int> suitableEnclosures;
    std::vector<std::string> suitableEnclosuresNames;

    for (int i = 0; i < Zoo::enclosureIds.size(); i++){
        int id = Zoo::enclosureIds[i];
        if (Zoo::enclosures[id]->enclosureType == Zoo::enclosures[oldEnclosureId]->enclosureType){
            suitableEnclosuresNames.push_back(Zoo::enclosures[id]->get_name() + " | " + std::to_string(Zoo::enclosures[id]->get_id()));
            //std::cout << INDENT << i << ": " << MAGENTA << Zoo::enclosures[id]->get_name() << RESET << " | " << Zoo::enclosures[id]->get_id() << "\n";
            suitableEnclosures.push_back(i);
        }
    }

    if (suitableEnclosures.size() <= 1) {
        //std::cout << RED << "You have no other suitable enclosures!\n" << RESET;
        return {0, true, std::string("You have no other suitable enclosures!"), RED};
    }

    int enclosureChoice = suitableEnclosures[optionSelector(suitableEnclosuresNames, std::string("Okay, which enclosure would you like to put it in: "), true)];

    if(!Zoo::enclosures[Zoo::enclosureIds[enclosureChoice]]->addAnimal(animalId, Zoo::animals.at(animalId))){
        //std::cout << RED << "Enclosure has no space!\n" << RESET;
        //delete newAnimalPtr; //Free memory if can't make it
        return {0, true, std::string("Enclosure has no space!"), RED};
    }

    Zoo::animals.at(animalId)->enclosureID = Zoo::enclosureIds[enclosureChoice];
    Zoo::enclosures.at(oldEnclosureId)->removeAnimal(animalId);

    return {0, true, std::string("Successfully moved animal!"), GREEN};
}
//function to breed animals 
Changes Zoo::breadAnimals(int money){

    int numAnimals = Zoo::animalIds.size();
// if breeding requirements are not 
// in terms of there not being two animals 
    if (numAnimals < 2){ 
        return {0, true, std::string("You have less than two animals!"), RED};
    }
// if breeding requirements are not 
// in terms of there not being enough funding 
    if (money < 10) {
        //std::cout << RED << "Insufficient funds to breed!\n" << RESET;
        return {0, true, std::string("Insufficient funds to breed!"), RED};
    } 

    std::vector<std::string> animalsToBreed;

    for (int i = 0; i < numAnimals; i++){
        int Id = Zoo::animalIds[i];

        animalsToBreed.push_back(Zoo::animals[Id]->get_name() 
                                + "(sex: " + sexToString(Zoo::animals[Id]->get_sex())
                                + ", age: " + std::to_string(round(Zoo::animals[Id]->get_age()))                                
                                + ", id: " + std::to_string(Id));
        /*
        std::cout << INDENT << i << ": " << BLUE << Zoo::animals[Id]->get_name() << RESET //name.
                      << " (sex: " << sexToString(Zoo::animals[Id]->get_sex()).
                      << ", age: " << (int) round(Zoo::animals[Id]->get_age()).
                      << ", id: " << Id << ")\n";.

        */
    }
//allows user to choose which animals are breesing 
//user picks a choice 1 
//user also picks a choice 2
    int choice1 = optionSelector(animalsToBreed, std::string("Choice 1: "), true);
    int choice2 = optionSelector(animalsToBreed, std::string("Choice 2: "), true);

    int animal1Id = Zoo::animalIds[choice1];
    int animal2Id = Zoo::animalIds[choice2];

    if (Zoo::animals.at(animal1Id)->enclosureID != Zoo::animals.at(animal2Id)->enclosureID){
        return {0, true, std::string("Animals must be from the same enclosure!"), RED};
    }

    int enclosureID = Zoo::animals.at(animal1Id)->enclosureID;

    if (Zoo::animals.at(animal1Id)->get_name() != Zoo::animals.at(animal2Id)->get_name()){
        return {0, true, std::string("Animals must be the same species!"), RED};
    }

    if ((Zoo::animals.at(animal1Id)->get_sex() != Zoo::animals.at(animal1Id)->get_sex())) {
        return {0, true, std::string("Animals must be of different sexes!"), RED};
    }

    if (Zoo::enclosures.at(enclosureID)->get_currentAnimals() >= Zoo::enclosures.at(enclosureID)->get_maxAnimals()){
        return {0, true, std::string("No room left in enclosure!"), RED};
    }

    if ((round(Zoo::animals.at(animal1Id)->get_age()) < 1.0) || (round(Zoo::animals.at(animal1Id)->get_age()) < 1.0)) {
        return {0, true, std::string("Animals must be of sexual maturity!"), RED};
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

    //Add pointer to Zoo object.
    newAnimalPtr->enclosureID = enclosureID;
    Zoo::enclosures[enclosureID]->addAnimal(id, newAnimalPtr);
    newAnimalPtr->set_cost(animalToPrice(type));
    Zoo::animals[id] = newAnimalPtr;
    Zoo::animalIds.push_back(id);

    return {10, true, std::string("Successfully bred animals!"), GREEN};
}
//allows user to build utilities such as toilet (not implemented)
 Changes Zoo::buildUtilities(int money){
    std::cout << "What Utility do you want to build: \n";
    Zoo::displayOptions(Zoo::utilitiesInformation);
    return {0, true, std::string("Successfully built utility!"), GREEN};
 }
//allows user to go to bank
//here user can borrow and pay loans 
Changes Zoo::goToBank(int money){

    std::vector<std::string> bankingOptions = {"Pay loan", "Get load"};

    int choice = optionSelector(bankingOptions, std::string("Welcome to the bank!"), true);

    if (choice == 0){ // Pay Loan Option.
        if (Zoo::bank.getNLoans() > 0){
            int loanIndex = optionSelector(Zoo::bank.getLoanInfo(), std::string("Which loan would you like to pay off?"), true);
            if (Zoo::bank.getLoan(loanIndex).amount > money){
                return {0, true, std::string("Insufficient funds!"), RED};
            }
            Zoo::bank.payLoan(loanIndex, money);
            return {money, true, std::string("Successfully paid off loan!"), GREEN};
        } else {
            return {0, true, std::string("You have no loans!"), GREEN};
        }
    } else { // Get Load Option.
        if (!Zoo::bank.checkCredit(money)){
            return {0, true, std::string("Your credit is too bad! You can't borrow more!"), RED};
        }
        int loanAmountChoice = optionSelector(Zoo::bank.loanAmounts, std::string("How much would you like to borrow? (Higher amount = higher interest)"), true);
        int loanAmount = Zoo::bank.loanAmountFromOption(loanAmountChoice);
        Zoo::bank.addLoan({loanAmount, Zoo::bank.interestRates[loanAmountChoice]});
        return {-loanAmount, true, std::string("Successfully borrowed $" + std::to_string(loanAmount) + "!"), GREEN};
    } 

    return {0, true, std::string("Successfully went to the bank!"), GREEN};

}