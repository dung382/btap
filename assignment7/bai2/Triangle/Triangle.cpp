#include "Triangle.hpp"
#include <iostream>
#include <cmath>

using namespace std;

Triangle::Triangle() : Polygon(TRIANGLE_SIDE_COUNT) {}

void Triangle::inputSideMeasurements() {
    cout << "[LOG] Enter measurements for 3 sides of the triangle:" << endl;
    for (int i = 0; i < TRIANGLE_SIDE_COUNT; i++) {
        cout << "  Side " << i + 1 << ": ";
        cin >> this->sideValues[i];
    }
}

int Triangle::calculateTotalPerimeter() const {
    return Polygon::calculateTotalPerimeter();
}

bool Triangle::verifyRightAngledProperty() const {
    int a = this->sideValues[0];
    int b = this->sideValues[1];
    int c = this->sideValues[2];

    long a2 = (long)a * a;
    long b2 = (long)b * b;
    long c2 = (long)c * c;

    return (a2 + b2 == c2) || (a2 + c2 == b2) || (b2 + c2 == a2);
}

double Triangle::calculateTriangleArea() const {
    double s = this->calculateTotalPerimeter() / 2.0;
    int a = sideValues[0], b = sideValues[1], c = sideValues[2];
    return sqrt(s * (s - a) * (s - b) * (s - c));
}