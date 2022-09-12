#pragma once
#include"ComplexNumber.h"
#include <vector>
#include "myException.h"
#include <iostream>
#include <utility>
#include "Equation.h"

class EquGroup
{
    typedef std::pair<ComplexNumber, ComplexNumber> Ty_X;
public:
    EquGroup(int num = 0) : m_numOfEqu(num) { m_equationSet.resize(num); }
    void reSetSize(int num) { m_equationSet.resize(num); m_numOfEqu = num; }
    void setGroup(std::vector<std::vector<double>> tCoef);
    void setGroup(std::vector<Equation> tEqu);
    void showGroup();
    std::vector<Ty_X> solveEquGroup();

private:
    std::vector<Equation> m_equationSet;
    int m_numOfEqu;
};
