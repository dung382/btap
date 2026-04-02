#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "../Polygon/Polygon.hpp"

class Triangle : public Polygon {
private:
    static const int TRIANGLE_SIDE_COUNT = 3;

public:
    Triangle();
    
    void inputSideMeasurements();
 
    int calculateTotalPerimeter() const override;
 
    bool verifyRightAngledProperty() const;
    
    double calculateTriangleArea() const;
};

#endif