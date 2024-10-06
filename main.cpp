#include "Zoo.h"
#include <iostream>
#include "game_logic.h"
#include "Player.h"
#include "LandEnclosure.h"

//#define DEBUG

#define START_FUNDS 10000
#define ROUNDS 20

int main(void){

    Player player(START_FUNDS);

    player.intro();
    player.getName();
    player.getAction();
    player.zoo.displayOptions(player.zoo.enclosureInformation);

    for (int round = 0; round < ROUNDS; round++){

    }

    return 0;
}