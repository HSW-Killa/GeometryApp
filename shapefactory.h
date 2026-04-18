#ifndef SHAPEFACTORY_H
#define SHAPEFACTORY_H

#include "Shape.h"
#include <memory>
#include <string>
#include <vector>

class ShapeFactory
{
public:
    enum class ShapeType { Circle, Rectangle, Triangle, Square };

    static std::unique_ptr<Shape> createShape(ShapeType type,
                                              const std::vector<double>& params);
    static std::string getTypeName(ShapeType type);
    static std::vector<std::string> getParamNames(ShapeType type);
};

#endif // SHAPEFACTORY_H
