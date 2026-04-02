#include "Point.hpp"
#include <cmath>
#include <stdexcept>

Point::Point() : x(0), y(0) {}
Point::Point(double x, double y) : x(x), y(y) {}
Point::Point(const Point& other) : x(other.x), y(other.y) {}
Point::~Point() {}

double Point::getX() const { return x; }
double Point::getY() const { return y; }

void Point::setX(double x) { this->x = x; }
void Point::setY(double y) { this->y = y; }

double Point::distance(const Point& other) const {
    return std::sqrt((x - other.x) * (x - other.x)
                   + (y - other.y) * (y - other.y));
}

double Point::dotProduct(const Point& other) const {
    return x * other.x + y * other.y;
}

Point Point::operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
Point Point::operator-(const Point& p) const { return Point(x - p.x, y - p.y); }

Point Point::operator*(double k) const { return Point(x * k, y * k); }

Point Point::operator/(double k) const {
    if (k == 0) throw std::runtime_error("Division by zero in Point::operator/");
    return Point(x / k, y / k);
}

Point& Point::operator+=(const Point& p) { x += p.x; y += p.y; return *this; }
Point& Point::operator-=(const Point& p) { x -= p.x; y -= p.y; return *this; }

Point& Point::operator*=(double k) { x *= k; y *= k; return *this; }

Point& Point::operator/=(double k) {
    if (k == 0) throw std::runtime_error("Division by zero in Point::operator/=");
    x /= k; y /= k;
    return *this;
}