#include "Circle.hpp"
#include <sstream>
#include <cmath>
#include <stdexcept>

static double PI() { return std::acos(-1.0); }

Circle::Circle() : center(), radius(0) {}

int Circle::type() const { return 2; }

double Circle::getArea() const {
    return PI() * radius * radius;
}

double Circle::getPerimeter() const {
    return 2.0 * PI() * radius;
}

void Circle::fromString(const std::string& s) {
    std::stringstream ss(s);
    double x, y, r;

    if (!(ss >> x >> y >> r))
        throw std::invalid_argument("Invalid input format: Circle (x y r)");

    if (r <= 0)
        throw std::invalid_argument("Radius must be positive");

    center = Point(x, y);
    radius = r;
}

// trả về đúng data format: "x y r"
std::string Circle::toString() const {
    std::stringstream ss;
    ss << center.getX() << " " << center.getY() << " " << radius;
    return ss.str();
}