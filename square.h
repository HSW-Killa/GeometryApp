#ifndef SQUARE_H
#define SQUARE_H

#include "Rectangle.h"

class Square : public Rectangle
{
public:
    Square(double side);
    ~Square() override = default;

    std::string getType() const override;
    std::string getParams() const override;
};

#endif // SQUARE_H
