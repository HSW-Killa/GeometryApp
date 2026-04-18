#include "Shape.h"

std::string Shape::toString() const
{
    return getType() + ": " + getParams() +
           " | Площадь: " + std::to_string(getArea()) +
           " | Периметр: " + std::to_string(getPerimeter());
}
