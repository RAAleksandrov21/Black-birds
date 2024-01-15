#include "account.h"
#include <iostream>
using namespace std;

void Account::deposit(double amount) 
{
    balance += amount;
    cout << "Deposit successful. New balance: " << balance << endl;
}

void Account::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
        cout << "Withdrawal successful. New balance: " << balance << endl;
    }
    else 
    {
        cout << "Insufficient funds." << endl;
    }
}

double Account::getBalance() const 
{
    return balance;
}

string Account::getAccountNumber() const 
{
    return accountNumber;
}

string Account::getAccountHolderName() const 
{
    return accountHolderName;
}

void BankAccount::deposit(double amount)
{
    // Additional logic for bank account deposits if needed
    Account::deposit(amount);
}

void BankAccount::withdraw(double amount)
{
    // Additional logic for bank account withdrawals if needed
    Account::withdraw(amount);
}
