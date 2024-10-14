#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <vector>

struct Loan {
    int amount; // the amount of the loan.
    float interest;// Value between 0 and 1.
};

class Bank {
    private:
    std::vector<Loan> loans;
    public:
    Bank();
    void addLoan(Loan); // used to add loans
    Loan getLoan(int); // used to observe loans
    int getNLoans(); // used t o get multiple loans
    void payLoan(int, int); // used to pay loan
    void incurInterest(); // used to incur interest
    int getTotal(); // used to get total 
    int getMinPayments();
};
#endif