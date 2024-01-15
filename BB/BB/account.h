#pragma once

#include <iostream>
#include <string>

class Account {
protected:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    Account(std::string accountNumber, std::string accountHolderName, double initialBalance)
        : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(initialBalance) {}

    virtual void deposit(double amount);

    virtual void withdraw(double amount);

    double getBalance() const;

    std::string getAccountNumber() const;

    std::string getAccountHolderName() const;
};

class BankAccount : public Account {
public:
    BankAccount(std::string accountNumber, std::string accountHolderName)
        : Account(accountNumber, accountHolderName, 0.0) {} // Set initial balance to 0

    void deposit(double amount) override;

    void withdraw(double amount) override;
};
