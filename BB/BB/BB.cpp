#include <iostream>
#include <vector>
#include <string>

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    double balance;

public:
    // Constructor
    BankAccount(std::string accountNumber, std::string accountHolderName, double initialBalance)
        : accountNumber(accountNumber), accountHolderName(accountHolderName), balance(initialBalance) {}

    // Member functions
    void deposit(double amount) {
        balance += amount;
        std::cout << "Deposit successful. New balance: " << balance << std::endl;
    }

    void withdraw(double amount) {
        if (amount > balance) {
            std::cout << "Insufficient funds." << std::endl;
        }
        else {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
        }
    }

    double getBalance() const {
        return balance;
    }

    // Getter for account number
    std::string getAccountNumber() const {
        return accountNumber;
    }
};

class Bank {
private:
    std::vector<BankAccount> accounts;

public:
    // Member functions
    void createAccount(std::string accountNumber, std::string accountHolderName, double initialBalance) {
        accounts.emplace_back(accountNumber, accountHolderName, initialBalance);
        std::cout << "Account created successfully." << std::endl;
    }

    void performTransaction(std::string accountNumber, char transactionType, double amount) {
        for (auto& account : accounts) {
            if (accountNumber == account.getAccountNumber()) {
                switch (transactionType) {
                case 'D':
                case 'd':
                    account.deposit(amount);
                    break;

                case 'W':
                case 'w':
                    account.withdraw(amount);
                    break;

                default:
                    std::cout << "Invalid transaction type." << std::endl;
                    break;
                }
                return;
            }
        }
        std::cout << "Account not found." << std::endl;
    }

    void checkBalance(std::string accountNumber) {
        for (const auto& account : accounts) {
            if (accountNumber == account.getAccountNumber()) {
                std::cout << "Account Balance: " << account.getBalance() << std::endl;
                return;
            }
        }
        std::cout << "Account not found." << std::endl;
    }
};

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
        case '1': {
            std::string accountNumber, accountHolderName;
            double initialBalance;
            std::cout << "Enter account number: ";
            std::cin >> accountNumber;
            std::cout << "Enter account holder name: ";
            std::cin.ignore(); // Ignore newline character in the buffer
            std::getline(std::cin, accountHolderName);
            std::cout << "Enter initial balance: ";
            std::cin >> initialBalance;
            bank.createAccount(accountNumber, accountHolderName, initialBalance);
            break;
        }

        case '2': {
            std::string accountNumber;
            double amount;
            std::cout << "Enter account number: ";
            std::cin >> accountNumber;
            std::cout << "Enter deposit amount: ";
            std::cin >> amount;
            bank.performTransaction(accountNumber, 'D', amount);
            break;
        }

        case '3': {
            std::string accountNumber;
            double amount;
            std::cout << "Enter account number: ";
            std::cin >> accountNumber;
            std::cout << "Enter withdrawal amount: ";
            std::cin >> amount;
            bank.performTransaction(accountNumber, 'W', amount);
            break;
        }

        case '4': {
            std::string accountNumber;
            std::cout << "Enter account number: ";
            std::cin >> accountNumber;
            bank.checkBalance(accountNumber);
            break;
        }

        case '5':
            std::cout << "Exiting the program.\n";
            break;

        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != '5');

    return 0;
}
