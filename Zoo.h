#ifndef ZOO_H
#define ZOO_H

#include <iostream>
#include <unordered_map> 
#include <memory>
#include <random>  
#include <math.h>
#include <algorithm>

#include "Animal.h"
#include "Enclosure.h"
#include "LandEnclosure.h"
#include "Tank.h"
#include "EnclosureInformation.h"
#include "AnimalInformation.h"
#include "AnimalMacros.h"
#include "Colours.h"
#include "Utilities.h"
#include "UtilitiesInformation.h"
#include "Bank.h"
#include "Input.h"

struct Changes{
    int costChange;
    bool isReturnMessage;
    std::string returnMessage;
    std::string colour;
};

struct DailySales{
    int visitors;
    int revenue;
};

class Zoo{

    protected:

    //Hashmap of Animals & Enclosures (maps id to pointer of object)
    std::vector<int> animalIds;
    std::vector<int> enclosureIds;

    std::unordered_map<int, std::shared_ptr<Animal>> animals;
    std::unordered_map<int, std::unique_ptr<Enclosure>> enclosures;


    //Actions to build starting infromation - should be private
    std::vector<EnclosureInformation> makeEnclosureInformation();
    std::vector<AnimalInformation> makeAnimalInformation();

    //Vectors of Possible Animals & Enclosures to purchase - should be private
    std::vector<EnclosureInformation> enclosureInformation;
    std::vector<AnimalInformation> animalInformation;
    std::vector<Utilities> UtilitiesVector;
    std::vector<UtilitiesInformation> utilitiesInformation;
    std::vector<UtilitiesInformation> makeUtilitiesInformation();

    int ticketPrice;

    std::vector<std::string> ticketPriceChoices;

    int ticketPriceFromOption(int);

    public:

    Bank bank;

    Zoo();

    std::string summary(std::string, int, int,  DailySales);

    void addAnimal(std::shared_ptr<Animal>);
    void addEnclosure(EnclosureInformation enclosureType);

    std::shared_ptr<Animal> getAnimalByID(int id);

    DailySales getRevenue();
    std::string ageAnimals(void);
    void deleteAnimal(int);

    //Player actions
    Changes buildEnclosure(int);
    Changes buildUtilities(int);
    Changes buyAnimal(int);
    Changes feedAnimal(int);
    template <typename T> int displayOptions(std::vector<T>);
    Changes setTicketPrice();
    Changes sellAnimal(void);
    Changes moveAnimal();
    Changes breadAnimals(int);
    Changes goToBank(int);

};
#endif

