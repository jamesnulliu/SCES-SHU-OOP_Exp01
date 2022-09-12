#pragma once
#include"ComplexNumber.h"
#include <vector>
#include "myException.h"
#include <iostream>
class Equation
{
public:
    friend std::istream &operator>>(std::istream &in, Equation &tEquation);
    friend std::ostream &operator<<(std::ostream &out, const Equation &tEquation);
    ComplexNumber &operator[](int index);
    const ComplexNumber &operator[](int index) const;
    Equation &operator=(const Equation &tEquation);
    Equation &operator=(const std::vector<double> &tEquation);
public:
    Equation(double a = 0, double b = 0, double c = 0)
    {
        coefSet.resize(3);
        delta = 0;
        coefSet[0] = a; coefSet[1] = b; coefSet[2] = c;
    }
    void calculateDelta() { delta = coefSet[1] * coefSet[1] + ComplexNumber(-4) * coefSet[0] * coefSet[2]; }
    ComplexNumber delta;
public:
    std::vector<ComplexNumber> coefSet;
};
