#include "Zoo.h"
#include <iostream>
#include <time.h>
#include "game_logic.h"
#include "Player.h"
#include "LandEnclosure.h"
#include "Input.h"

//#define DEBUG

#define START_FUNDS 2000
#define ROUNDS_PER_TURN 4
#define TURNS 100

int main(void){

    setRawMode(true);
    clearScreen();

    srand((unsigned)time(NULL));

    Player player(START_FUNDS);

    player.intro();

    //player.zoo.buildUtilities(0);
    int week;
    int day;
    //player.getName();
    //Action action = player.getAction();
    //player.doAction(action);
    //player.zoo.displayOptions(player.zoo.enclosureInformation);
    //player.zoo.displayOptions(player.zoo.animalInformation);

    std::string message = "";

    DailySales dailySales = {0,0};

    for (week = 0; week < TURNS; week++){
        for (int day = 0; day < ROUNDS_PER_TURN; day++){

            message += player.zoo.summary("Test",player.money,week*ROUNDS_PER_TURN+day+1,dailySales);

            Action action = player.getAction(message);
            message = player.doAction(action) + "\n";
            dailySales = player.zoo.getRevenue();
            player.money += dailySales.revenue;
            player.zoo.bank.incurInterest();
        }
        message = message + "\n" + player.zoo.ageAnimals();
        player.chargeInterest(true);
        player.checkBankruptcy();

    }

    return 0;
}