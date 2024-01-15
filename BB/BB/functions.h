#pragma once

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Account; // Forward declaration

class MyBank 
{
private:
    vector<Account*> accounts;

public:
    bool isNumeric(const string& str);

    void createAccount();

    void performTransaction(char transactionType);

    void transferDigitalAssets();

    void checkBalance();

    ~MyBank();
};
