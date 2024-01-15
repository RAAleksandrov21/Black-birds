void Account::deposit(double amount) {
    balance += amount;
    std::cout << "Deposit successful. New balance: " << balance << std::endl;
}

void Account::withdraw(double amount) {
    if (balance >= amount) {
        balance -= amount;
        std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
    }
    else {
        std::cout << "Insufficient funds.\n";
    }
}

double Account::getBalance() const {
    return balance;
}

std::string Account::getAccountNumber() const {
    return accountNumber;
}