#ifndef QUADRILATERAL_HPP
#define QUADRILATERAL_HPP

#include "../Polygon/Polygon.hpp"

class Quadrilateral : public Polygon {
private:
    static const int QUAD_SIDE_COUNT = 4;

public:
    Quadrilateral();
    void inputQuadrilateralSides();
    int calculateTotalPerimeter() const override;
    double calculateQuadrilateralArea() const;
};

#endif