#include "Zoo.h"
#include <iostream>
#include <time.h>
#include "game_logic.h"
#include "Player.h"
#include "LandEnclosure.h"

//#define DEBUG

#define START_FUNDS 10000
#define ROUNDS 20

int main(void){

    srand( (unsigned)time(NULL) );

    Player player(START_FUNDS);

    player.intro();
    player.getName();
    //Action action = player.getAction();
    //player.doAction(action);
    //player.zoo.displayOptions(player.zoo.enclosureInformation);
    //player.zoo.displayOptions(player.zoo.animalInformation);

    for (int round = 0; round < ROUNDS; round++){
        Action action = player.getAction();
        player.doAction(action);
    }

    return 0;
}