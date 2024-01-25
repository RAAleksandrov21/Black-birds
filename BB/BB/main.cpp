#include "functions.h"
#include <iostream>

using namespace std;

int main() {
    MyBank myBank;
    char choice;

    title();

    do {

        cout << endl << "Menu:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Transfer Your Will" << endl;
        cout << "5. Check Balance" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            system("cls");
            title();
            cout << "Invalid input. Please enter a valid choice." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) {
        case '1':
            myBank.createAccount();
            break;

        case '2':
            myBank.performTransaction('D');
            break;

        case '3':
            myBank.performTransaction('W');
            break;

        case '4':
            myBank.transferDigitalAssets();
            break;

        case '5':
            myBank.checkBalance();
            break;

        case '6':
            cout << "Exiting the program." << endl;
            break;

        default:
            system("cls");
            title();
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '6');

    return 0;
}