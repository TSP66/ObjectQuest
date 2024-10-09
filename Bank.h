#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <vector>

struct Loan {
    int amount;
    float interest; // Value between 0 and 1
};

class Bank {
    private:
    std::vector<Loan> loans;
    public:
    Bank();
    void addLoan(Loan);
    Loan getLoan(int);
    int getNLoans();
    void payLoan(int, int);
    void incurInterest();
    int getTotal();
    int getMinPayments();
};

#endif