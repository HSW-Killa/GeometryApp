#include "Rectangle.h"

Rectangle::Rectangle(double width, double height)
    : m_width(width), m_height(height) {}

double Rectangle::getArea() const
{
    return m_width * m_height;
}

double Rectangle::getPerimeter() const
{
    return 2 * (m_width + m_height);
}

std::string Rectangle::getType() const
{
    return "Прямоугольник";
}

std::string Rectangle::getParams() const
{
    return "W=" + std::to_string(m_width) + ", H=" + std::to_string(m_height);
}
