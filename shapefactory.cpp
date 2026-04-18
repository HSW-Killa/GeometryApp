#include "ShapeFactory.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Square.h"

std::unique_ptr<Shape> ShapeFactory::createShape(ShapeType type,
                                                 const std::vector<double>& params)
{
    switch (type) {
    case ShapeType::Circle:
        if (params.size() >= 1) return std::make_unique<Circle>(params[0]);
        break;
    case ShapeType::Rectangle:
        if (params.size() >= 2) return std::make_unique<Rectangle>(params[0], params[1]);
        break;
    case ShapeType::Triangle:
        if (params.size() >= 3) return std::make_unique<Triangle>(params[0], params[1], params[2]);
        break;
    case ShapeType::Square:
        if (params.size() >= 1) return std::make_unique<Square>(params[0]);
        break;
    }
    return nullptr;
}

std::string ShapeFactory::getTypeName(ShapeType type)
{
    switch (type) {
    case ShapeType::Circle: return "Круг";
    case ShapeType::Rectangle: return "Прямоугольник";
    case ShapeType::Triangle: return "Треугольник";
    case ShapeType::Square: return "Квадрат";
    default: return "";
    }
}

std::vector<std::string> ShapeFactory::getParamNames(ShapeType type)
{
    switch (type) {
    case ShapeType::Circle: return {"Радиус"};
    case ShapeType::Rectangle: return {"Ширина", "Высота"};
    case ShapeType::Triangle: return {"Сторона A", "Сторона B", "Сторона C"};
    case ShapeType::Square: return {"Сторона"};
    default: return {};
    }
}
