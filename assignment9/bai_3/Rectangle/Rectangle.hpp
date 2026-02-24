#pragma once
#include "../../bai_1/Point.hpp"
#include "../../bai_2/Shape.hpp"

class Rectangle : public Shape {
private:
    Point center;
    double width, height;

public:
    Rectangle();

    double getArea() const override;
    double getPerimeter() const override;

    int type() const override;

    void fromString(const std::string& s) override;
    std::string toString() const override;
};