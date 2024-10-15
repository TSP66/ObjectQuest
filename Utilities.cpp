#include <iostream>
#include "Utilities.h"

Utilities :: Utilities(){ //default utilities constructor 
    revenue = 100;
    cost = 1000;
}
//toilet constructor. 
//price and revnue 
Toilet :: Toilet(){ 
    revenue = 100;
    cost = 1000;
    name = "Toilet";
}
//giftshop constructor 
//price and revenue 
GiftShop :: GiftShop(){
    revenue = 400;
    cost = 3000;
    name = "Gift Shop";
}
//fountain constructor 
//price and revenue 
Fountain :: Fountain(){
    revenue = 50;
    cost = 500;
    name = "Fountain";
}


