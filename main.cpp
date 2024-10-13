#include "Zoo.h"
#include <iostream>
#include <time.h>
#include "game_logic.h"
#include "Player.h"
#include "LandEnclosure.h"
#include "Input.h"

#define START_FUNDS 0 // The player has to take out a loan to get started
#define ROUNDS_PER_TURN 4
#define TURNS 100

int main(void){

    setRawMode(true);
    clearScreen();

    srand((unsigned)time(NULL));

    Player player(START_FUNDS);

    player.intro();

    std::string message = "";

    DailySales dailySales = {0,0};

    for (int week = 0; week < TURNS; week++){
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
        if (player.checkBankruptcy()){
            std::cout << RED << "You have been bankrupted!\n" << RESET;
            goto end;
        }
    }
    end:
    std::cout << "\n\nThank you for playing!\n";
    return 0;
}