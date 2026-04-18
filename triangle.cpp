#include "Triangle.h"
#include <cmath>

Triangle::Triangle(double sideA, double sideB, double sideC)
    : m_sideA(sideA), m_sideB(sideB), m_sideC(sideC) {}

double Triangle::getPerimeter() const
{
    return m_sideA + m_sideB + m_sideC;
}

double Triangle::getArea() const
{
    double p = getPerimeter() / 2;
    return sqrt(p * (p - m_sideA) * (p - m_sideB) * (p - m_sideC));
}

std::string Triangle::getType() const
{
    return "Треугольник";
}

std::string Triangle::getParams() const
{
    return "A=" + std::to_string(m_sideA) +
           ", B=" + std::to_string(m_sideB) +
           ", C=" + std::to_string(m_sideC);
}
