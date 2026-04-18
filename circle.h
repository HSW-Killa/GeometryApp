#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
public:
    Circle(double radius);
    ~Circle() override = default;

    double getArea() const override;
    double getPerimeter() const override;
    std::string getType() const override;
    std::string getParams() const override;

private:
    double m_radius;
};

#endif // CIRCLE_H
