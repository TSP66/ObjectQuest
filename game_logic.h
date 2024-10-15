#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <iostream>
#include <string>
#include <unordered_map> 

enum Action{
    BUILD_ENCLOSURE,
    BUY_ANIMAL,
    SELL_ANIMAL,
    MOVE_ANIMAL,
    BREED_ANIMAL,
    FEED_ANIMAL,
    SET_TICKET_PRICE,
    GO_TO_BANK,
    NUM_ACTIONS, 
};

//this maps the turn based options that the player has 
inline std::unordered_map<Action, std::string> getActionNameMap(void){

    std::unordered_map<Action, std::string> map ={

        {BUILD_ENCLOSURE, "Build Enclosure"},// allows user to choose from a set of enclosures that cost different amounts of money
        {BUY_ANIMAL, "Buy Animal"},//allows user to buy animal and place them in an owened enclosure 
        {SELL_ANIMAL, "Sell Animal"},//allows for user to sell animal to return a portion of the animal cost 
        {MOVE_ANIMAL, "Move Animal"},// allows for the user to move animals to different enclosures 
        {BREED_ANIMAL, "Breed Animal"},//breed animal option allows user to breed 2 animals that meet the requirmetns 
        {FEED_ANIMAL, "Feed Animal"},//feed animals option used to ensure animals stay happy which brings in  more customers 
        {SET_TICKET_PRICE, "Set ticket price"}, //allows for yhe user to change the price that visitors must pay to enter
        {GO_TO_BANK, "Go to bank"}, //takes you to bank options here you can make loans and pay loans
        {NUM_ACTIONS, "Do nothing"},// allows the user to do nothing for a turn.
        //this can allow the user to build up funds 
        
    };

    return map;
} 

#endif