#pragma once
#include "../../bai_1/Point.hpp"
#include "../../bai_2/Shape.hpp"

class Triangle : public Shape {
private:
    Point a, b, c;

public:
    Triangle();

    double getArea() const override;
    double getPerimeter() const override;

    int type() const override;

    void fromString(const std::string& s) override;
    std::string toString() const override;
};