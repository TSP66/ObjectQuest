#include "Player.h"

Player::Player(int money) : money(money){
    Player::zoo = Zoo();
    Player::ActionNameMap = getActionNameMap();
    Player::zoo.bank.addLoan({money,0.02});
}

void Player::intro(){
    //Put intro stuff here
    //Welcome to Zoo stuff
}

void Player::getName(void){
    std::cout << "Enter the name of your zoo: ";
    std::cin >> Player::name;
}

Action Player::getAction(void){

    std::vector<std::string> actions = std::vector<std::string>{
        "Build an Enclosure",
        "Buy an Animal",
        "Sell an Animal",
        "Move an Animal",
        "Breed an Animal",
        "Feed an Animal",
        "Set Ticket Price",
        "Go to the Bank",
        "Invalid Option"
    };

    int action = optionSelector(actions);

    return (Action) action;
}


bool Player::doAction(Action action){
    Changes result;
    switch(action){

        case BUILD_ENCLOSURE:
        result = Player::zoo.buildEnclosure(Player::money);
        break;

        case BUY_ANIMAL:
        result = Player::zoo.buyAnimal(Player::money);
        break;

        case SELL_ANIMAL:
        result = Player::zoo.sellAnimal();
        //SELL_ANIMAL
        break;

        case MOVE_ANIMAL:
        result = Player::zoo.moveAnimal();
        //MOVE_ANIMAL
        break;

        case BREED_ANIMAL:
        //BREED_ANIMAL
        result = Player::zoo.breadAnimals(Player::money);
        break;

        case FEED_ANIMAL:
        result = Player::zoo.feedAnimal(Player::money);
        //FEED_ANIMAL
        break;

        case SET_TICKET_PRICE:
        result = Player::zoo.setTicketPrice();
        //SET_TICKET_PRICE
        break;

        case GO_TO_BANK:
        result = {0}; // result = Player::zoo.goToBank(Player::money)
        break;

        case NUM_ACTIONS:
        result = {0}; //Just to keep the compiler happy
        //INVALID Option
        break;

    }
    Player::money -= result.costChange;
    return true;
}

void Player::chargeInterest(bool display){
    int payment = Player::zoo.bank.getMinPayments();
    Player::money -= Player::zoo.bank.getMinPayments();
    if (display){
        std::cout << "You were charged " << RED << "$" << payment << RESET << " on your loan!\n";
    }
}

bool Player::checkBankruptcy(){
    return Player::money < 0;
}