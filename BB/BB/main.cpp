#include "functions.h"
#include "iomanip"
#include <iostream>

using namespace std;

int main() {
    MyBank myBank;
    char choice;

    do {
        
        cout << setw(60) << R"(
                            __________  _____ ____   ____  ___    _   ____ __
                           / ____/ __ \/ ___//  _/  / __ )/   |  / | / / //_/
                          / __/ / /_/ /\__ \ / /   / __  / /| | /  |/ /   /  
                         / /___/ __ _/___/ // /   / /_/ / ___ |/ /|  / /| |  
                        /_____/_/ |_|/____/___/  /_____/_/  |_/_/ |_/_/ |_|  
        )" << endl;
         

        cout << endl << "Menu:" << endl;
        cout << "1. Create Account" << endl;;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Transfer Digital Assets" << endl;
        cout << "5. Check Balance" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle invalid input
        if (cin.fail()) 
        {
            cout << "Invalid input. Please enter a valid choice." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        switch (choice) 
        {
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
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '6');

    return 0;
}
