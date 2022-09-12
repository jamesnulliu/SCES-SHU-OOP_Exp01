#pragma once
#include <iostream>
#include "myException.h"

class ComplexNumber
{
public:
    friend std::ostream &operator<<(std::ostream &out, const ComplexNumber &tNum);
    ComplexNumber operator=(const ComplexNumber &tNum);
    ComplexNumber operator=(double i);
    ComplexNumber operator*(const ComplexNumber &tNum);
    ComplexNumber operator+(const ComplexNumber &tNum);
    ComplexNumber operator-(const ComplexNumber &tNum);
    ComplexNumber operator/(const ComplexNumber &tNum);
    ComplexNumber operator++();

    bool operator>(double i);
    bool operator<(double i);
    bool operator==(double i);

    ComplexNumber Csqrt();
    double getReal() { return m_real; }
    double getimag() { return m_imag; }
public:
    ComplexNumber(double r = 0, double i = 0) :m_real(r), m_imag(i) {}
private:
    double m_real;
    double m_imag;
};
