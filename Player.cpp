#include "Player.h"

Player::Player(int money) : money(money){
    Player::zoo = Zoo();
    Player::ActionNameMap = getActionNameMap();
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

    std::cout << "Select your action:\n";

    for (int i = 0; i <= NUM_ACTIONS; i++){
        std::cout << "    " << i << ": " << Player::ActionNameMap[(Action) i] << "\n";
    }
    std::cout << "Action: ";
    //Print stuff to ask player for action
    //Return an action enum
    int action;
    std::cin >> action;

    if ((action < 0) || (action > NUM_ACTIONS)){
        std::cout << "Invalid action! Try again\n";
        return Player::getAction(); //Try again if value is not within bounds
    }

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

        case NUM_ACTIONS:
        result = {0}; //Just to keep the compiler happy
        //INVALID Option
        break;

    }
    Player::money -= result.costChange;
    return true;
}