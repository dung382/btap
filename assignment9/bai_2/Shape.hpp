#pragma once
#include <string>

class Shape {
public:
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;

    // type: 0 Triangle, 1 Rectangle, 2 Circle, 3 Ellipse
    virtual int type() const = 0;

    virtual void fromString(const std::string& s) = 0;
    // toString() tra ve"data" (khong kem type), defactory tu ghi type ra file
    virtual std::string toString() const = 0;
};