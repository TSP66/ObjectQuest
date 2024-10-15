#include "Bank.h"
// bank.cpp used to determine all financial aspecets of the game

std::vector<std::string> Bank::loanAmounts = {
    "$100",  "$200",   "$500",   "$1000",  "$2000",
    "$5000", "$10000", "$20000", "$50000", "$100000"};
std::vector<float> Bank::interestRates = {0.02, 0.03, 0.04, 0.05, 0.06,
                                          0.07, 0.08, 0.09, 0.10, 0.11};

Bank::Bank() {}
// used to add loan. players can borrow money from bank
void Bank::addLoan(Loan loan) { Bank::loans.push_back(loan); }

Loan Bank::getLoan(int index) { return Bank::loans[index]; }

// loans must be paid and are erased once loans have been paid
void Bank::makePayment(int amount) {
  int total = amount;
  for (int i = 0; i < Bank::loans.size(); i++) {
    if (Bank::loans[i].amount >= total) {
      Bank::payLoan(i, total);
      return;
    } else {
      total -= Bank::loans[i].amount;
      Bank::payLoan(i, total);
    }
  }
}

// function removes loans
// loans are erased when paid for
void Bank::payLoan(int index, int amount) {
  Bank::loans[index].amount -= amount;
  if (Bank::loans[index].amount <= 0) {
    Bank::loans.erase(Bank::loans.begin() + index);
  }
}

// loans incur interest the longer they arent paid for
void Bank::incurInterest() {
  for (int i = 0; i < Bank::loans.size(); i++) {
    Bank::loans[i].amount =
        (int)((float)Bank::loans[i].amount * (1.0 + Bank::loans[i].interest));
  }
}

// returns the total amount of moneu loaned
int Bank::getTotal() {
  int sum = 0;
  for (Loan loan : Bank::loans) {
    sum += loan.amount;
  }
  return sum;
}

bool Bank::checkCredit(int playerMoney) {
  if (playerMoney < Bank::getTotal()) {
    return false;  // Player has negative equity
  }
  return true;
}

int Bank::getMinPayments() {
  return Bank::getTotal() / 10;  // You have to pay 10% off every cycle
}

// returns the size of bank loans
int Bank::getNLoans() { return (int)Bank::loans.size(); }

// returns all information about current loans that are in play
std::vector<std::string> Bank::getLoanInfo(void) {
  std::vector<std::string> loanInfo;
  for (int i = 0; i < Bank::loans.size(); i++) {
    std::string message =
        INDENT + "Loan " + std::to_string(i) + ": $" +
        std::to_string(Bank::loans[i].amount) +
        ", Interest: " + std::to_string(Bank::loans[i].interest * 100.0) + " %";
    loanInfo.push_back(message);
  }
  return loanInfo;
}

int Bank::loanAmountFromOption(int option) {
  return atoi(Bank::loanAmounts[option]
                  .substr(1, Bank::loanAmounts.size() - 1)
                  .c_str());
}
