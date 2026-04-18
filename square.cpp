#include "Square.h"

Square::Square(double side) : Rectangle(side, side) {}

std::string Square::getType() const
{
    return "Квадрат";
}

std::string Square::getParams() const
{
    return "Сторона=" + std::to_string(m_width);
}
