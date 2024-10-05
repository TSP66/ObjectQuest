#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Zoo.h"
#include "game_logic.h"

class Player{
    private:
    std::string name;
    std::unordered_map<Action, std::string> ActionNameMap;
    public:
    Player(int);
    void intro();
    void getName(void);
    Action getAction(void);
    void doAction(Action);
    int money;
    Zoo zoo;
};


#endif