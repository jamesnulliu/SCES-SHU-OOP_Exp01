#include "../header/ComplexNumber.h"
std::ostream &operator<<(std::ostream &out, const ComplexNumber &tNum)
{
    out << tNum.m_real;
    if (tNum.m_imag > 0) {
        out << " + " << tNum.m_imag << "i";
    } else if (tNum.m_imag < 0) {
        out << " - " << -tNum.m_imag << "i";
    }
    return out;
}

ComplexNumber ComplexNumber::operator=(const ComplexNumber &tNum)
{
    m_real = tNum.m_real;
    m_imag = tNum.m_imag;
    return *this;
}

ComplexNumber ComplexNumber::operator=(double i)
{
    m_real = i;
    m_imag = 0;
    return *this;
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber &tNum)
{
    double r = m_real * tNum.m_real - m_imag * tNum.m_imag;
    double i = m_real * tNum.m_imag + m_imag * tNum.m_real;
    return { r, i };
}

ComplexNumber ComplexNumber::operator+(const ComplexNumber &tNum)
{
    double r = m_real + tNum.m_real;
    double i = m_imag + tNum.m_imag;
    return ComplexNumber(r, i);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber &tNum)
{
    double r = m_real - tNum.m_real;
    double i = m_imag - tNum.m_imag;
    return { r, i };
}

ComplexNumber ComplexNumber::operator/(const ComplexNumber &tNum)
{
    if (tNum.m_imag == 0) {
        if (tNum.m_real == 0) { throw CalculationError("Cannot divide 0."); }
        return ComplexNumber(m_real / tNum.m_real, m_imag / tNum.m_real);
    }
    double r = (m_real * tNum.m_real + m_imag * tNum.m_imag) / (tNum.m_real * tNum.m_real + tNum.m_imag * tNum.m_imag);
    double i = (m_real * tNum.m_imag + m_imag * tNum.m_real) / (tNum.m_real * tNum.m_real + tNum.m_imag * tNum.m_imag);
    return { r, i };
}

ComplexNumber ComplexNumber::operator++()
{
    ComplexNumber temp = *this;
    m_real++;
    return temp;
}

bool ComplexNumber::operator>(double i)
{
    if (m_imag != 0) { throw CalculationError("Connot compare 2 imaginary numbers."); }
    return m_real > i;
}
bool ComplexNumber::operator<(double i)
{
    if (m_imag != 0) { throw CalculationError("Connot compare 2 imaginary numbers."); }
    return m_real < i;
}
bool ComplexNumber::operator==(double i)
{
    if (m_imag != 0) { throw CalculationError("Connot compare 2 imaginary numbers."); }
    return m_real == i;
}
ComplexNumber ComplexNumber::Csqrt()
{
    if (m_imag != 0) {
        throw CalculationError("Cannot sqrt a imaginary number.");
    }
    return { sqrt(m_real) };
}