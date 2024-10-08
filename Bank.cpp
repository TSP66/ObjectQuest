#include "Bank.h"

Bank::Bank(){

}

void Bank::addLoan(Loan loan){
    Bank::loans.push_back(loan);
}

Loan Bank::getLoan(int index){
    return Bank::loans[index];
}


void Bank::payLoan(int index, int amount){
    Bank::loans[index].amount -= amount;
    if (Bank::loans[index].amount <= 0){
        Bank::loans.erase(Bank::loans.begin() + index);
    }
}

void Bank::incurInterest(){
    for(int i = 0; i < Bank::loans.size(); i++){
        Bank::loans[i].amount = (int) ((float) Bank::loans[i].amount * (1.0 + Bank::loans[i].interest));
    }
}

int Bank::getTotal(){
    int sum = 0;
    for (Loan loan : Bank::loans) {
        sum += loan.amount;
    }
    return sum;
}

int Bank::getMinPayments(){
    return Bank::getTotal()/20; //You have to pay 5% off every
}

int Bank::getNLoans(){
    return (int) Bank::loans.size();
}