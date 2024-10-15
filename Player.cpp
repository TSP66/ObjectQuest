#include "Player.h"

Player::Player(int money) : money(money){

    Player::zoo = Zoo();
    Player::ActionNameMap = getActionNameMap();
    
    if (money > 0){
        Player::zoo.bank.addLoan({money,0.02});
    }

    Player::actions = std::vector<std::string>{
        "Build an Enclosure",
        "Buy an Animal",
        "Sell an Animal",
        "Move an Animal",
        "Breed an Animal",
        "Feed an Animal",
        "Set Ticket Price",
        "Go to the Bank",
        "Do nothing",
    };
}

std::string Player::intro(){
    //Put intro stuff here
    //Welcome to Zoo stuff
    return "Intro message";
}

void Player::getName(void){
    std::cout << "Enter the name of your zoo: ";
    std::cin >> Player::name;
}

Action Player::getAction(std::string message){

    int action = optionSelector(Player::actions, message, true);

    return (Action) action;
}


std::string Player::doAction(Action action){
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
        result = Player::zoo.goToBank(Player::money);
        break;

        case NUM_ACTIONS:
        result = {0}; //Just to keep the compiler happy
        //INVALID Option
        break;

    }

    Player::money -= result.costChange;

    if (result.isReturnMessage){
        return result.colour + result.returnMessage + RESET;
    }

    return "";
}

std::string Player::chargeInterest(bool display){
    int payment = Player::zoo.bank.getMinPayments();
    Player::zoo.bank.makePayment(payment);
    Player::money -= payment;
    if (display && payment > 0){
        return  "You were charged " + RED + "$" + std::to_string(payment) + RESET + " on your loan!\n";
    }
    return "";
}

bool Player::checkBankruptcy(){
    return Player::money < 0;
}