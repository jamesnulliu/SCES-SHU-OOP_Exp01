#include "../header/EquGroup.h"

void EquGroup::setGroup(std::vector<std::vector<double>> tCoef)
{
    if (tCoef.size() != m_numOfEqu) { throw VectorIndexError("Number of param equations does not match number of current EquGroup object."); }
    for (int i = 0; i < m_numOfEqu; ++i) {
        m_equationSet[i] = tCoef[i];
        m_equationSet[i].calculateDelta();
    }
}

void EquGroup::setGroup(std::vector<Equation> tEqu)
{
    if (tEqu.size() != m_numOfEqu) { throw VectorIndexError("Number of param equations does not match number of current EquGroup object."); }
    for (int i = 0; i < m_numOfEqu; ++i) {
        m_equationSet[i] = tEqu[i];
        m_equationSet[i].calculateDelta();
    }
}

void EquGroup::showGroup()
{
    for (int i = 0; i < m_numOfEqu; ++i) {
        std::cout << "* |- ·½³Ì " << i + 1 << ": " << m_equationSet[i] << std::endl;
    }
}

std::vector<EquGroup::Ty_X> EquGroup::solveEquGroup()
{
    std::vector<Ty_X> solution;
    ComplexNumber x1(0), x2(0);
    for (Equation e : m_equationSet) {
        if (e.coefSet[0] == 0) {
            if (e.coefSet[2] == 0) {
                throw CalculationError("Meet a function with infinit results.");
            } else if (e.coefSet[1] == 0) {
                throw CalculationError("Meet a function can not be solved.");
            }
            int x = -1 * e.coefSet[2].getReal() / e.coefSet[1].getReal();
            CalculationError err("Meet a linear equation. Result X is " + std::to_string(x) + ".");
            err.show();
            throw err;
        }
        if (e.delta > 0) {
            x1 = (ComplexNumber(-1) * e.coefSet[1] + e.delta.Csqrt()) / ComplexNumber(2) / e.coefSet[0];
            x2 = (ComplexNumber(-1) * e.coefSet[1] - e.delta.Csqrt()) / ComplexNumber(2) / e.coefSet[0];
            solution.push_back({ x1,x2 });
        } else if (e.delta == 0) {
            x1 = (ComplexNumber(-1) * e.coefSet[1] + e.delta.Csqrt()) / ComplexNumber(2) / e.coefSet[0];
            solution.push_back({ x1,x1 });
        } else {
            x1 = (ComplexNumber(-1) * e.coefSet[1] + ComplexNumber(0, sqrt(-e.delta.getReal()))) / ComplexNumber(2) / e.coefSet[0];
            x2 = (ComplexNumber(-1) * e.coefSet[1] - ComplexNumber(0, sqrt(-e.delta.getReal()))) / ComplexNumber(2) / e.coefSet[0];
            solution.push_back({ x1,x2 });
        }
    }
    return solution;
}