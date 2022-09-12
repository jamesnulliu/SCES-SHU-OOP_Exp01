#include "../header/Equation.h"
std::istream &operator>>(std::istream &in, Equation &tEquation)
{
    double temp[3] = { 0 };
    in >> temp[0] >> temp[1] >> temp[2];
    for (int i = 0; i < 3; i++) {
        tEquation.coefSet[i] = temp[i];
    }
    return in;
}

std::ostream &operator<<(std::ostream &out, const Equation &tEquation)
{
    out << '(' << tEquation[0] << ")x^2 + " << '(' << tEquation[1] << ")x + (" << tEquation[2] << ") = 0";
    return out;
}

ComplexNumber &Equation::operator[](int index)
{
    if (index >= coefSet.size()) { throw VectorIndexError(); }
    return coefSet[index];
}

const ComplexNumber &Equation::operator[](int index) const
{
    if (index >= coefSet.size()) { throw VectorIndexError(); }
    return coefSet[index];
}

Equation &Equation::operator=(const Equation &tEquation)
{
    coefSet = tEquation.coefSet;
    return *this;
}

Equation &Equation::operator=(const std::vector<double> &tEquation)
{
    for (int i = 0; i < 3; ++i) {
        coefSet[i] = tEquation[i];
    }
    return *this;
}