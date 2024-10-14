#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Zoo.h"
#include "game_logic.h"
#include "Bank.h"

class Player{
    private:
    std::string name;
    std::unordered_map<Action, std::string> ActionNameMap;
    std::vector<std::string> actions;
    public:
    Player(int);
    std::string intro();
    void getName(void);
    Action getAction(std::string message);
    std::string doAction(Action);
    std::string chargeInterest(bool);
    int money;
    Zoo zoo;
    bool checkBankruptcy();
};


#endif