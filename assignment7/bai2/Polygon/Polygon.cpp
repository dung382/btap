#include "Polygon.hpp"
#include <iostream>

using namespace std;

Polygon::Polygon(int n) : sideCount(n) {
    this->sideValues = new int[this->sideCount];
}

Polygon::~Polygon() {
    delete[] this->sideValues;
}

int Polygon::calculateTotalPerimeter() const {
    int perimeter = 0;
    for (int i = 0; i < this->sideCount; i++) {
        perimeter += this->sideValues[i];
    }
    return perimeter;
}

void Polygon::displaySideMeasurements() const {
    cout << "Side measurements: ";
    for (int i = 0; i < this->sideCount; i++) {
        cout << this->sideValues[i] << (i == this->sideCount - 1 ? "" : ", ");
    }
}