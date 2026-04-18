#include "Circle.h"

Circle::Circle(double radius) : m_radius(radius) {}

double Circle::getArea() const
{
    return M_PI * m_radius * m_radius;
}

double Circle::getPerimeter() const
{
    return 2 * M_PI * m_radius;
}

std::string Circle::getType() const
{
    return "Круг";
}

std::string Circle::getParams() const
{
    return "R=" + std::to_string(m_radius);
}
