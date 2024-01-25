#pragma once

#include <iostream>
#include <vector>
#include <string>

class Account;

class MyBank {
private:
    std::vector<Account*> accounts;

public:
    bool isNumeric(const std::string& str);

    void createAccount();

    void performTransaction(char transactionType);

    void transferDigitalAssets();

    void checkBalance();

    ~MyBank();
};

void title();