#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <vector>

#include "Input.h" //For INDENT

struct Loan {
    int amount; // the amount of the loan.
    float interest;// Value between 0 and 1.
};

class Bank {
    private:
    std::vector<Loan> loans;
    public:
    static std::vector<std::string> loanAmounts;
    static std::vector<float> interestRates;
    Bank();
    void addLoan(Loan);//used to add loans
    Loan getLoan(int);//used to observe loans
    int getNLoans();//used to get multiple loans
    void payLoan(int, int);//used to pay loan
    void incurInterest();//used to incur interest
    int getTotal();//used to get total 
    int getMinPayments();
    std::vector<std::string> getLoanInfo(void);
    int loanAmountFromOption(int);
    bool checkCredit(int); //used to check money in back 
    void makePayment(int);// used to make a payment with money in your bank 
};
#endif


