#include "account.h"
#include "functions.h"
#include <iostream>


void Account::deposit(double amount)
{
    balance += amount;
    system("cls");
    title();
    std::cout << "Deposit successful. New balance: " << balance << std::endl;
}

void Account::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
        system("cls");
        title();
        std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
    }
    else
    {
        system("cls");
        title();
        std::cout << "Insufficient funds." << std::endl;
    }
}

double Account::getBalance() const
{
    return balance;
}

std::string Account::getAccountNumber() const
{
    return accountNumber;
}

std::string Account::getAccountHolderName() const
{
    return accountHolderName;
}

void BankAccount::deposit(double amount)
{
    Account::deposit(amount);
}

void BankAccount::withdraw(double amount)
{
    Account::withdraw(amount);
}

void Account::saveToFile() const {
    std::ofstream file(accountNumber + ".txt");
    file << accountHolderName << "\n";
    file << balance << "\n";
    file.close();
}

void BankAccount::saveToFile() const {
    Account::saveToFile();
}