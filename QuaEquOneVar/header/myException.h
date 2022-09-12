#pragma once
#include <iostream>
#include <string>
class VectorIndexError
{
public:
    VectorIndexError(const std::string &str = "Vecotr out of range.") :message(str) {}
    void show() { std::cout << message << std::endl; }
private:
    std::string message;
};

class CalculationError
{
public:
    CalculationError(const std::string &str = "Calculation error.") :message(str) {}
    void show() { std::cout << message << std::endl; }
private:
    std::string message;
};
