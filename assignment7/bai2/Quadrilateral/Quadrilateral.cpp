#include "Quadrilateral.hpp"
#include <iostream>

using namespace std;

Quadrilateral::Quadrilateral() : Polygon(QUAD_SIDE_COUNT) {}

void Quadrilateral::inputQuadrilateralSides() {
    cout << "[LOG] Enter measurements for 4 sides of the quadrilateral:" << endl;
    for (int i = 0; i < QUAD_SIDE_COUNT; i++) {
        cout << "  Side " << i + 1 << ": ";
        cin >> this->sideValues[i];
    }
}

int Quadrilateral::calculateTotalPerimeter() const {
    return Polygon::calculateTotalPerimeter();
}

double Quadrilateral::calculateQuadrilateralArea() const {
    cout << "[LOG] Area calculation for general quadrilateral requires more data." << endl;
    return 0.0;
}