#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape
{
public:
    virtual ~Shape() = default;

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual std::string getType() const = 0;
    virtual std::string getParams() const = 0;
    virtual std::string toString() const;
};

#endif // SHAPE_H
