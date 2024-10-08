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
    public:
    Player(int);
    void intro();
    void getName(void);
    Action getAction(void);
    bool doAction(Action);
    void chargeInterest(bool);
    int money;
    Zoo zoo;
    bool checkBankruptcy();
};


#endif