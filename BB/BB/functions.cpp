#include "functions.h"

void createAccount(Bank& bank) {
    std::string accountNumber, accountHolderName;
    double initialBalance;
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;
    std::cout << "Enter account holder name: ";
    std::cin.ignore();
    std::getline(std::cin, accountHolderName);
    std::cout << "Enter initial balance: ";
    std::cin >> initialBalance;
    bank.createAccount(accountNumber, accountHolderName, initialBalance);
}

void deposit(Bank& bank) {
    std::string accountNumber;
    double amount;
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;
    std::cout << "Enter deposit amount: ";
    std::cin >> amount;
    bank.performTransaction(accountNumber, 'D', amount);
}

void withdraw(Bank& bank) {
    std::string accountNumber;
    double amount;
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;
    std::cout << "Enter withdrawal amount: ";
    std::cin >> amount;
    bank.performTransaction(accountNumber, 'W', amount);
}

void checkBalance(Bank& bank) {
    std::string accountNumber;
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;
    bank.checkBalance(accountNumber);
}
