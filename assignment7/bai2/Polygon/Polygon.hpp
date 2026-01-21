#ifndef POLYGON_HPP
#define POLYGON_HPP

class Polygon {
protected:
    int sideCount;      
    int* sideValues;    

public:
    Polygon(int n);
    virtual ~Polygon(); 
    
    virtual int calculateTotalPerimeter() const; 
    void displaySideMeasurements() const;
};

#endif