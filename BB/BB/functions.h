#pragma once

#include <iostream>
#include <vector>
#include <string>

class Account; // Forward declaration

class MyBank {
private:
    std::vector<Account*> accounts;

public:
    bool isNumeric(const std::string& str);
};