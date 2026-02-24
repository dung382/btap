#pragma once
#include <iostream>

class Point {
private:
    double x, y;

public:
    Point();
    Point(double x, double y);
    Point(const Point& other);
    ~Point();

    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);

    double distance(const Point& other) const;
    double dotProduct(const Point& other) const;

    // Operator overloading
    Point operator+(const Point& p) const;
    Point operator-(const Point& p) const;

    Point operator*(double k) const;
    Point operator/(double k) const;

    Point& operator+=(const Point& p);
    Point& operator-=(const Point& p);

    Point& operator*=(double k);
    Point& operator/=(double k);
};