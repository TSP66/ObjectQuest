#include "Player.h"

Player::Player(int money) : money(money){
    Player::zoo = Zoo();
}

void Player::intro(){
    //Put intro stuff here
    //Welcome to Zoo stuff
}

void Player::getName(void){
    std::cout << "Enter the name of your zoo: ";
    std::cin >> Player::name;
}