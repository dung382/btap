#include "Rectangle.hpp"
#include <sstream>
#include <stdexcept>

Rectangle::Rectangle() : center(), width(0), height(0) {}

int Rectangle::type() const { return 1; }

double Rectangle::getArea() const { return width * height; }

double Rectangle::getPerimeter() const { return 2.0 * (width + height); }

void Rectangle::fromString(const std::string& s) {
    std::stringstream ss(s);
    double x, y, w, h;

    if (!(ss >> x >> y >> w >> h))
        throw std::invalid_argument("Invalid input format: Rectangle (x y w h)");

    if (w <= 0 || h <= 0)
        throw std::invalid_argument("Invalid rectangle size (w,h must be > 0)");

    center = Point(x, y);
    width = w;
    height = h;
}

// "x y w h"
std::string Rectangle::toString() const {
    std::stringstream ss;
    ss << center.getX() << " " << center.getY() << " " << width << " " << height;
    return ss.str();
}