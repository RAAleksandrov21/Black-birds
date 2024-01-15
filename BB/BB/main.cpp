#include <iostream>
#include "functions.h"

int main() {
    Bank bank;
    char choice;

    do {
        std::cout << "\nMenu:\n";
        std::cout << "1. Create Account\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Check Balance\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case '1':
            createAccount(bank);
            break;

        case '2':
            deposit(bank);
            break;

        case '3':
            withdraw(bank);
            break;

        case '4':
            checkBalance(bank);
            break;

        case '5':
            std::cout << "Exiting the program.\n";
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5');

    return 0;
}
