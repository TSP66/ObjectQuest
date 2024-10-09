#ifndef UTILITIES_H
#define UTILITIES_H
#include <iostream>

class Utilities {
    protected :
    int revenue;
    int cost;
    std::string name;
    public : 
    Utilities();
};

class Toilet : protected Utilities{
    private : 
    public :
    Toilet();
};

class GiftShop : protected Utilities{
    private : 
    public :
    GiftShop();
};

class Fountain : protected Utilities{
    private : 
    public :
    Fountain();
};

#endif