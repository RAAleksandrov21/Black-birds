#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <vector>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(std::string accountNumber, std::string accountHolderName, double initialBalance);

    // Member functions
    void deposit(double amount);

    void withdraw(double amount);

    double getBalance() const;

    // Getter for account number
    std::string getAccountNumber() const;
};

class Bank {
private:
    std::vector<BankAccount> accounts;

public:
    // Member functions
    void createAccount(std::string accountNumber, std::string accountHolderName, double initialBalance);

    void performTransaction(std::string accountNumber, char transactionType, double amount);

    void checkBalance(std::string accountNumber);
};

#endif // BANK_H
