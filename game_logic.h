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
    NUM_ACTIONS, // LEAVE THIS LAST
};

//This might make sense to move into the intializaton of the player class
//Inlined to avoid compiler errors [and to optimize :)]
inline std::unordered_map<Action, std::string> getActionNameMap(void){

    std::unordered_map<Action, std::string> map = {

        {BUILD_ENCLOSURE, "Build Enclosure"},
        {BUY_ANIMAL, "Buy Animal"},
        {SELL_ANIMAL, "Sell Animal"},
        {MOVE_ANIMAL, "Move Animal"},
        {BREED_ANIMAL, "Breed Animal"},
        {FEED_ANIMAL, "Feed Animal"},
        {SET_TICKET_PRICE, "Set ticket price"}
        
    };

    return map;
} 

#endif