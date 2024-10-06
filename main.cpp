#include "Zoo.h"
#include <iostream>
#include <time.h>
#include "game_logic.h"
#include "Player.h"
#include "LandEnclosure.h"

//#define DEBUG

#define START_FUNDS 10000
#define ROUNDS 20000

int main(void){

    srand( (unsigned)time(NULL) );

    Player player(START_FUNDS);

    player.intro();

    int day = 0;
    //player.getName();
    //Action action = player.getAction();
    //player.doAction(action);
    //player.zoo.displayOptions(player.zoo.enclosureInformation);
    //player.zoo.displayOptions(player.zoo.animalInformation);

    for (day = 0; day < ROUNDS; day++){
        Action action = player.getAction();
        player.doAction(action);
        DailySales dailySales = player.zoo.getRevenue();
        player.money += dailySales.revenue;
        player.zoo.summary("Test",player.money,day,dailySales);
    }

    return 0;
}