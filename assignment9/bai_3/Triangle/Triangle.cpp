#include "Triangle.hpp"
#include <sstream>
#include <cmath>
#include <stdexcept>

Triangle::Triangle() : a(), b(), c() {}

int Triangle::type() const { return 0; }

double Triangle::getPerimeter() const {
    return a.distance(b) + b.distance(c) + c.distance(a);
}

double Triangle::getArea() const {
    double ab = a.distance(b);
    double bc = b.distance(c);
    double ca = c.distance(a);
    double p = (ab + bc + ca) / 2.0;
    return std::sqrt(std::max(0.0, p * (p - ab) * (p - bc) * (p - ca)));
}

void Triangle::fromString(const std::string& s) {
    std::stringstream ss(s);
    double x1, y1, x2, y2, x3, y3;

    if (!(ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3))
        throw std::invalid_argument("Invalid input format: Triangle (x1 y1 x2 y2 x3 y3)");

    a = Point(x1, y1);
    b = Point(x2, y2);
    c = Point(x3, y3);

    // check triangle inequality
    double ab = a.distance(b);
    double bc = b.distance(c);
    double ca = c.distance(a);

    if (ab + bc <= ca || ab + ca <= bc || bc + ca <= ab)
        throw std::logic_error("Invalid triangle (triangle inequality violated)");
}

// "x1 y1 x2 y2 x3 y3"
std::string Triangle::toString() const {
    std::stringstream ss;
    ss << a.getX() << " " << a.getY() << " "
       << b.getX() << " " << b.getY() << " "
       << c.getX() << " " << c.getY();
    return ss.str();
}