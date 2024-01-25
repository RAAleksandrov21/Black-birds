#include "functions.h"
#include "account.h"
#include <iostream>
#include <sstream>
#include <limits>
#include <fstream>
#include <iomanip>

void title()
{
    std::cout << std::setw(60) << R"(
            __________  _____ ____   ____  ___    _   ____ __
           / ____/ __ \/ ___//  _/  / __ )/   |  / | / / //_/
          / __/ / /_/ /\__ \ / /   / __  / /| | /  |/ /   /  
         / /___/ __ _/___/ // /   / /_/ / ___ |/ /|  / /| |  
        /_____/_/ |_|/____/___/  /_____/_/  |_/_/ |_/_/ |_|  
        )" << std::endl;
}

bool MyBank::isNumeric(const std::string& str) {
    std::stringstream ss(str);
    double num;
    return (ss >> num) && ss.eof();
}

void MyBank::createAccount() {
    std::string accountNumber, accountHolderName;

    // Check if the account number is numeric
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;
    if (!isNumeric(accountNumber)) {
        system("cls");
        title();
        std::cout << "Invalid input.\n";
        return;
    }

    // Check if the account holder name is numeric
    std::cout << "Enter account holder name: ";
    std::cin.ignore();
    std::getline(std::cin, accountHolderName);
    if (isNumeric(accountHolderName)) {
        system("cls");
        title();
        std::cout << "Invalid input.\n";
        return;
    }

    auto newAccount = new BankAccount(accountNumber, accountHolderName);
    accounts.push_back(newAccount);
    newAccount->saveToFile(); // Save the new account to a file
    system("cls");
    title();
    std::cout << "Account created successfully with an initial balance of 0.\n";
}

void MyBank::performTransaction(char transactionType) {
    std::string accountNumber, accountHolderName;
    double amount;

    // Check if the account number is numeric
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;
    if (!isNumeric(accountNumber)) {
        system("cls");
        title();
        std::cout << "Invalid input.\n";
        return;
    }

    // Check if the account holder name is numeric
    std::cout << "Enter account holder name: ";
    std::cin.ignore();
    std::getline(std::cin, accountHolderName);
    if (isNumeric(accountHolderName)) {
        system("cls");
        title();
        std::cout << "Invalid input.\n";
        return;
    }

    // Check if the account exists
    for (auto& account : accounts) {
        if (accountNumber == account->getAccountNumber() && accountHolderName == account->getAccountHolderName()) {
            switch (transactionType) {
            case 'D':
            case 'd':
                std::cout << "Enter deposit amount: ";
                std::cin >> amount;
                account->deposit(amount);
                account->saveToFile(); // Save the updated account to a file
                return;

            case 'W':
            case 'w':
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                account->withdraw(amount);
                account->saveToFile(); // Save the updated account to a file
                return;

            default:
                system("cls");
                title();
                std::cout << "Invalid transaction type.\n";
                return;
            }
        }
    }
    system("cls");
    title();
    std::cout << "Account not found or account holder name does not match.\n";
}

void MyBank::transferDigitalAssets() {
    std::string fromAccountNumber, fromAccountHolderName, toAccountNumber, toAccountHolderName;
    double amount;

    // Check if the sender's account number is numeric
    std::cout << "Enter sender's account number: ";
    std::cin >> fromAccountNumber;
    if (!isNumeric(fromAccountNumber)) {
        system("cls");
        title();
        std::cout << "Invalid input.\n";
        return;
    }

    // Check if the sender's account holder name is numeric
    std::cout << "Enter sender's account holder name: ";
    std::cin.ignore();
    std::getline(std::cin, fromAccountHolderName);
    if (isNumeric(fromAccountHolderName)) {
        system("cls");
        title();
        std::cout << "Invalid input.\n";
        return;
    }

    // Check if the recipient's account number is numeric
    std::cout << "Enter recipient's account number: ";
    std::cin >> toAccountNumber;
    if (!isNumeric(toAccountNumber)) {
        system("cls");
        title();
        std::cout << "Invalid input.\n";
        return;
    }

    // Check if the recipient's account holder name is numeric
    std::cout << "Enter recipient's account holder name: ";
    std::cin.ignore();
    std::getline(std::cin, toAccountHolderName);
    if (isNumeric(toAccountHolderName)) {
        system("cls");
        title();
        std::cout << "Invalid input.\n";
        return;
    }

    // Check if both sender and recipient accounts exist
    Account* fromAccount = nullptr;
    Account* toAccount = nullptr;

    for (auto& account : accounts) {
        if (account->getAccountNumber() == fromAccountNumber && account->getAccountHolderName() == fromAccountHolderName) {
            fromAccount = account;
        }
        else if (account->getAccountNumber() == toAccountNumber && account->getAccountHolderName() == toAccountHolderName) {
            toAccount = account;
        }

        // Exit the loop if both accounts are found
        if (fromAccount != nullptr && toAccount != nullptr) {
            break;
        }
    }

    // Check if the sender has sufficient funds
    if (fromAccount != nullptr && toAccount != nullptr) {
        std::cout << "Enter amount to transfer: ";
        std::cin >> amount;

        if (fromAccount->getBalance() >= amount) {
            // Perform the transfer
            fromAccount->withdraw(amount);
            toAccount->deposit(amount);
            system("cls");
            title();
            std::cout << "Digital assets transferred successfully.\n";
        }
        else {
            system("cls");
            title();
            std::cout << "Insufficient funds.\n";
        }
    }
    else {
        system("cls");
        title();
        std::cout << "One or more accounts not found or account holder name does not match.\n";
    }
}

void MyBank::checkBalance() {
    std::string accountNumber, accountHolderName;

    // Check if the account number is numeric
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;
    std::cin >> accountNumber;
    if (!isNumeric(accountNumber)) {
        system("cls");
        title();
        std::cout << "Invalid input.\n";
        return;
    }

    // Check if the account holder name is numeric
    std::cout << "Enter account holder name: ";
    std::cin.ignore();
    std::getline(std::cin, accountHolderName);
    if (isNumeric(accountHolderName)) {
        system("cls");
        title();
        std::cout << "Invalid input.\n";
        return;
    }

    // Check if the account exists
    for (const auto& account : accounts) {
        if (accountNumber == account->getAccountNumber() && accountHolderName == account->getAccountHolderName()) {
            std::cout << "Account Balance: " << account->getBalance() << std::endl;
            return;
        }
    }
    system("cls");
    title();
    std::cout << "Account not found or account holder name does not match.\n";
}



MyBank::~MyBank() {
    for (auto& account : accounts) {
        delete account;
    }
}