#include "Triangle.hpp"
#include <iostream>
#include "Quadrilateral.hpp"

using namespace std;

int main() {
    int triangleCount;
    cout << "=== TRIANGLE ANALYZER SYSTEM ===" << endl;
    cout << "Enter the number of triangles (n): ";
    cin >> triangleCount;
    
    Triangle* triangleList = new Triangle[triangleCount];

    for (int i = 0; i < triangleCount; i++) {
        cout << "\n[Input] Triangle #" << i + 1 << ":" << endl;
        triangleList[i].inputSideMeasurements();
    }

    cout << "\n=== RESULTS: PYTHAGOREAN TRIANGLES ===" << endl;
    bool found = false;
    for (int i = 0; i < triangleCount; i++) {
        if (triangleList[i].verifyRightAngledProperty()) {
            cout << "Triangle #" << i + 1 << " is Right-Angled:" << endl;
            cout << "  - Sides: ";
            triangleList[i].displaySideMeasurements(); 
            cout << "\n  - Total Perimeter: " << triangleList[i].calculateTotalPerimeter() << endl;
            cout << "\n  - Total Triang Area: " << triangleList[i].calculateTriangleArea() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No triangles in the list satisfy the Pythagorean theorem." << endl;
    }

    cout << "\n--- QUADRILATERAL TESTING ---" << endl;
    Quadrilateral q;
    q.inputQuadrilateralSides();
    
    cout << "\nResult for Quadrilateral:" << endl;
    cout << "  - Sides: ";
    q.displaySideMeasurements();
    cout << "\n  - Total Perimeter: " << q.calculateTotalPerimeter() << endl;

    delete[] triangleList;
    return 0;
}