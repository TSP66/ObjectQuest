#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "Zoo.h"

class Player{
    private:
    std::string name;
    public:
    Player(int);
    void intro();
    void getName(void);
    int money;
    Zoo zoo;
};


#endif