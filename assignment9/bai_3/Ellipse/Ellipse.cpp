#include "Ellipse.hpp"
#include <sstream>
#include <cmath>
#include <stdexcept>

static double PI() { return std::acos(-1.0); }

Ellipse::Ellipse() : center(), rx(0), ry(0) {}

int Ellipse::type() const { return 3; }

double Ellipse::getArea() const {
    return PI() * rx * ry;
}

// Ramanujan approximation
double Ellipse::getPerimeter() const {
    return PI() * (3.0 * (rx + ry) - std::sqrt((3.0 * rx + ry) * (rx + 3.0 * ry)));
}

void Ellipse::fromString(const std::string& s) {
    std::stringstream ss(s);
    double x, y, a, b;

    if (!(ss >> x >> y >> a >> b))
        throw std::invalid_argument("Invalid input format: Ellipse (x y rx ry)");

    if (a <= 0 || b <= 0)
        throw std::invalid_argument("Invalid ellipse radius (rx,ry must be > 0)");

    center = Point(x, y);
    rx = a;
    ry = b;
}

// "x y rx ry"
std::string Ellipse::toString() const {
    std::stringstream ss;
    ss << center.getX() << " " << center.getY() << " " << rx << " " << ry;
    return ss.str();
}