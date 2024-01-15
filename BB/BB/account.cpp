void Account::deposit(double amount) {
    balance += amount;
    std::cout << "Deposit successful. New balance: " << balance << std::endl;
}