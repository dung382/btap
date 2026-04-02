#include <iostream>
#include <vector>
#include "bai_4/ShapeFactory.hpp"

int main() {
    std::vector<Shape*> shapes;
    try {
        shapes = ShapeFactory::readShapesFromFile("data/input.txt");
    }
    catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }

    for (const auto& shape : shapes) {
        std::cout << "Type = " << shape->type()
                  << " | Data = " << shape->toString() << "\n";
        std::cout << "Area = " << shape->getArea() << "\n";
        std::cout << "Perimeter = " << shape->getPerimeter() << "\n";
        std::cout << "-----------------------------\n";
    }

    try {
        ShapeFactory::saveShapesToFile("data/output.txt", shapes);
    }
    catch (const std::exception& e) {
        std::cerr << "Save error: " << e.what() << std::endl;
    }

    for (auto shape : shapes) delete shape;
    shapes.clear();
    return 0;
}