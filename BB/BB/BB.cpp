#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount
{
private:
    string accountNumber;
    string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(string accountNumber, string accountHolderName, double initialBalance)
        : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(initialBalance) {}

    // Member functions
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposit successful. New balance: " << balance << endl;
    }

    void withdraw(double amount)
    {
        if (amount > balance)
        {
            cout << "Insufficient funds." << endl;
        }
        else
        {
            balance -= amount;
            cout << "Withdrawal successful. New balance: " << balance << endl;
        }
    }

    double getBalance() const
    {
        return balance;
    }

    // Getter for account number
    string getAccountNumber() const
    {
        return accountNumber;
    }
};

class Bank
{
private:
    vector<BankAccount> accounts;

public:
    // Member functions
    void createAccount(string accountNumber, string accountHolderName, double initialBalance)
    {
        accounts.emplace_back(accountNumber, accountHolderName, initialBalance);
        cout << "Account created successfully." << endl;
    }

    void performTransaction(string accountNumber, char transactionType, double amount)
    {
        for (auto& account : accounts)
        {
            if (accountNumber == account.getAccountNumber())
            {
                switch (transactionType)
                {
                case 'D':
                case 'd':
                    account.deposit(amount);
                    break;

                case 'W':
                case 'w':
                    account.withdraw(amount);
                    break;

                default:
                    cout << "Invalid transaction type." << endl;
                    break;
                }
                return;
            }
        }
        cout << "Account not found." << endl;
    }

    void checkBalance(string accountNumber)
    {
        for (const auto& account : accounts)
        {
            if (accountNumber == account.getAccountNumber())
            {
                cout << "Account Balance: " << account.getBalance() << endl;
                return;
            }
        }
        cout << "Account not found." << endl;
    }
};

int main()
{

    Bank bank;
    char choice;

    do
    {

        cout << endl << "Menu:" << endl;
        cout << "1. Create Account" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Check Balance" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
        {
            string accountNumber, accountHolderName;
            double initialBalance;
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter account holder name: ";
            cin.ignore(); // Ignore newline character in the buffer
            getline(cin, accountHolderName);
            cout << "Enter initial balance: ";
            cin >> initialBalance;
            bank.createAccount(accountNumber, accountHolderName, initialBalance);
            break;
        }

        case '2':
        {
            string accountNumber;
            double amount;
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter deposit amount: ";
            cin >> amount;
            bank.performTransaction(accountNumber, 'D', amount);
            break;
        }

        case '3':
        {
            string accountNumber;
            double amount;
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            bank.performTransaction(accountNumber, 'W', amount);
            break;
        }

        case '4':
        {
            string accountNumber;
            cout << "Enter account number: ";
            cin >> accountNumber;
            bank.checkBalance(accountNumber);
            break;
        }

        case '5':
            cout << "Exiting the program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}
