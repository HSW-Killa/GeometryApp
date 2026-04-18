#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape
{
public:
    Triangle(double sideA, double sideB, double sideC);
    ~Triangle() override = default;

    double getArea() const override;
    double getPerimeter() const override;
    std::string getType() const override;
    std::string getParams() const override;

private:
    double m_sideA, m_sideB, m_sideC;
};

#endif // TRIANGLE_H
