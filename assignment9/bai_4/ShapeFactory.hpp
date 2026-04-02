#pragma once
#include <vector>
#include <string>
#include "../bai_2/Shape.hpp"

class ShapeFactory {
public:
    static Shape* createShape(int type, const std::string& data);
    static std::vector<Shape*> readShapesFromFile(const std::string& filename);
    static void saveShapesToFile(
        const std::string& filename,
        const std::vector<Shape*>& shapes
    );
};