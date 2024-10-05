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
    for (int i = 0; i < NUM_ACTIONS; i++){
        std::cout << "    " << i << ": " << Player::ActionNameMap[(Action) i] << "\n";
    }
    std::cout << "Action: ";
    //Print stuff to ask player for action
    //Return an action enum
    int action;
    std::cin >> action;

    if ((action < 0) || (action >= NUM_ACTIONS)){
        return Player::getAction(); //Try again if value is not within bounds
    }

    return (Action) action;
}


void Player::doAction(Action action){
    switch(action){

        case BUILD_ENCLOSURE:
        //BUILD_ENCLOSURE
        break;

        case BUY_ANIMAL:
        //BUY_ANIMAL
        break;

        case SELL_ANIMAL:
        //SELL_ANIMAL
        break;

        case MOVE_ANIMAL:
        //MOVE_ANIMAL
        break;

        case BREED_ANIMAL:
        //BREED_ANIMAL
        break;

        case FEED_ANIMAL:
        //FEED_ANIMAL
        break;

        case SET_TICKET_PRICE:
        //SET_TICKET_PRICE
        break;

        case NUM_ACTIONS:
        //INVALID Option
        break;

    }
}