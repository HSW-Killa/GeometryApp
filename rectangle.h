#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height);
    ~Rectangle() override = default;

    double getArea() const override;
    double getPerimeter() const override;
    std::string getType() const override;
    std::string getParams() const override;

protected:
    double m_width;
    double m_height;
};

#endif // RECTANGLE_H
