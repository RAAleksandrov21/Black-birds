#pragma once

#include <iostream>
#include <string>
using namespace std;

class Account 
{
protected:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    Account(string accountNumber, string accountHolderName, double initialBalance)
        : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(initialBalance) {}

    virtual void deposit(double amount);

    virtual void withdraw(double amount);

    double getBalance() const;

    string getAccountNumber() const;

    string getAccountHolderName() const;
};

class BankAccount : public Account 
{
public:
    BankAccount(string accountNumber, string accountHolderName)
        : Account(accountNumber, accountHolderName, 0.0) {} // Set initial balance to 0

    void deposit(double amount) override;

    void withdraw(double amount) override;
};
