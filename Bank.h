#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <vector>

#include "Input.h" //For INDENT

struct Loan {
    int amount;
    float interest; // Value between 0 and 1
};

class Bank {
    private:
    std::vector<Loan> loans;
    public:
    static std::vector<std::string> loanAmounts;
    static std::vector<float> interestRates;
    Bank();
    void addLoan(Loan);
    Loan getLoan(int);
    int getNLoans();
    void payLoan(int, int);
    void incurInterest();
    int getTotal();
    int getMinPayments();
    std::vector<std::string> getLoanInfo(void);
    int loanAmountFromOption(int);
    bool checkCredit(int);
};

#endif