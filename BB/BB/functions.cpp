#include "functions.h"
#include "account.h"
#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

bool MyBank::isNumeric(const string& str) {
    stringstream ss(str);
    double num;
    return (ss >> num) && ss.eof();
}

void MyBank::createAccount() {
    string accountNumber, accountHolderName;

    // Validate if the account number is numeric
    cout << "Enter account number: ";
    cin >> accountNumber;
    if (!isNumeric(accountNumber)) {
        cout << "Invalid input.\n";
        return;
    }

    // Validate if the account holder name is numeric
    cout << "Enter account holder name: ";
    cin.ignore(); // Ignore newline character in the buffer
    getline(cin, accountHolderName);
    if (isNumeric(accountHolderName)) {
        cout << "Invalid input.\n";
        return;
    }
    accounts.push_back(new BankAccount(accountNumber, accountHolderName));
    cout << "Account created successfully with an initial balance of 0.\n";
}

void MyBank::performTransaction(char transactionType) {
    string accountNumber, accountHolderName;
    double amount;

    // Validate if the account number is numeric
    cout << "Enter account number: ";
    cin >> accountNumber;
    if (!isNumeric(accountNumber)) {
        cout << "Invalid input.\n";
        return;
    }

    // Validate if the account holder name is numeric
    cout << "Enter account holder name: ";
    cin.ignore(); // Ignore newline character in the buffer
    getline(cin, accountHolderName);
    if (isNumeric(accountHolderName)) {
        cout << "Invalid input.\n";
        return;
    }

    // Check if the account exists
    for (auto& account : accounts) {
        if (accountNumber == account->getAccountNumber() && accountHolderName == account->getAccountHolderName()) {
            switch (transactionType) {
            case 'D':
            case 'd':
                cout << "Enter deposit amount: ";
                cin >> amount;
                account->deposit(amount);
                return;

            case 'W':
            case 'w':
                cout << "Enter withdrawal amount: ";
                cin >> amount;
                account->withdraw(amount);
                return;

            default:
                cout << "Invalid transaction type." << endl;
                return;
            }
        }
    }
    cout << "Account not found or account holder name does not match." << endl;
}

void MyBank::transferDigitalAssets() {
    string fromAccountNumber, fromAccountHolderName, toAccountNumber, toAccountHolderName;
    double amount;

    // Validate if the sender's account number is numeric
    cout << "Enter sender's account number: ";
    cin >> fromAccountNumber;
    if (!isNumeric(fromAccountNumber)) {
        cout << "Invalid input.\n";
        return;
    }

    // Validate if the sender's account holder name is numeric
    cout << "Enter sender's account holder name: ";
    cin.ignore(); // Ignore newline character in the buffer
    getline(cin, fromAccountHolderName);
    if (isNumeric(fromAccountHolderName)) {
        cout << "Invalid input.\n";
        return;
    }

    // Validate if the recipient's account number is numeric
    cout << "Enter recipient's account number: ";
    cin >> toAccountNumber;
    if (!isNumeric(toAccountNumber)) {
        cout << "Invalid input.\n";
        return;
    }

    // Validate if the recipient's account holder name is numeric
    cout << "Enter recipient's account holder name: ";
    cin.ignore(); // Ignore newline character in the buffer
    getline(cin, toAccountHolderName);
    if (isNumeric(toAccountHolderName)) {
        cout << "Invalid input.\n";
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
        cout << "Enter amount to transfer: ";
        cin >> amount;

        if (fromAccount->getBalance() >= amount) {
            // Perform the transfer
            fromAccount->withdraw(amount);
            toAccount->deposit(amount);
            cout << "Digital assets transferred successfully.\n";
        }
        else {
            cout << "Insufficient funds.\n";
        }
    }
    else {
        cout << "One or more accounts not found or account holder name does not match.\n";
    }
}

void MyBank::checkBalance() {
    string accountNumber, accountHolderName;

    // Validate if the account number is numeric
    cout << "Enter account number: ";
    cin >> accountNumber;
    if (!isNumeric(accountNumber)) {
        cout << "Invalid input.\n";
        return;
    }

    // Validate if the account holder name is numeric
    cout << "Enter account holder name: ";
    cin.ignore(); // Ignore newline character in the buffer
    getline(cin, accountHolderName);
    if (isNumeric(accountHolderName)) {
        cout << "Invalid input.\n";
        return;
    }

    // Check if the account exists
    for (const auto& account : accounts) {
        if (accountNumber == account->getAccountNumber() && accountHolderName == account->getAccountHolderName()) {
            cout << "Account Balance: " << account->getBalance() << endl;
            return;
        }
    }
    cout << "Account not found or account holder name does not match." << endl;
}

MyBank::~MyBank() {
    for (auto& account : accounts) {
        delete account;
    }
}
