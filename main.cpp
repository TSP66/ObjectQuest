#include "Zoo.h"
#include <iostream>
#include <time.h>
#include "game_logic.h"
#include "Player.h"
#include "LandEnclosure.h"

//#define DEBUG

#define START_FUNDS 2000
#define ROUNDS_PER_TURN 4
#define TURNS 100

int main(void){

    srand((unsigned)time(NULL));

    Player player(START_FUNDS);

    player.intro();

    int week = 0;

    for (week = 0; week < TURNS; week++){
        for (int day = 0; day < ROUNDS_PER_TURN; day++){

            Action action = player.getAction();
            player.doAction(action);
            DailySales dailySales = player.zoo.getRevenue();
            player.money += dailySales.revenue;
            player.zoo.summary("Test",player.money,week*ROUNDS_PER_TURN+day+1,dailySales);
            player.zoo.bank.incurInterest();
        }
        player.zoo.ageAnimals();
        player.chargeInterest(true);
        player.checkBankruptcy();

    }

    return 0;
}