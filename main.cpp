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
    clearScreen(); //clears screen using ANSI escape code

    srand((unsigned)time(NULL));

    Player player(START_FUNDS);

    std::string message = player.intro();

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
        message = message + "\n" + player.zoo.ageAnimals() + "\n";
        message = message + "\n" + player.chargeInterest(true) + "\n";
        if (player.checkBankruptcy()){
            std::cout << RED << "You have been bankrupted due to debt repayments!\n" << RESET;
            goto end;
        }
        if (player.checkVictory()){
            std::cout << GREEN << "You have won the game!\n" << RESET;
            goto end;
        }
    }
    end:
    std::cout << "\n\nThank you for playing!\n";
    return 0;
}