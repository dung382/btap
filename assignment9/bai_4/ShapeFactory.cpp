#include "ShapeFactory.hpp"

#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>

// include các shape cụ thể
#include "../bai_3/Circle/Circle.hpp"
#include "../bai_3/Ellipse/Ellipse.hpp"
#include "../bai_3/Rectangle/Rectangle.hpp"
#include "../bai_3/Triangle/Triangle.hpp"

Shape* ShapeFactory::createShape(int type, const std::string& data) {
    Shape* shape = nullptr;

    switch (type) {
    case 0: shape = new Triangle(); break;
    case 1: shape = new Rectangle(); break;
    case 2: shape = new Circle(); break;
    case 3: shape = new Ellipse(); break;
    default:
        throw std::invalid_argument("Unknown shape type: " + std::to_string(type));
    }

    shape->fromString(data);
    return shape;
}

std::vector<Shape*> ShapeFactory::readShapesFromFile(const std::string& filename) {
    std::vector<Shape*> shapes;
    std::ifstream file(filename);

    if (!file.is_open())
        throw std::runtime_error("Cannot open input file: " + filename);

    std::string line;
    while (std::getline(file, line)) {
        try {
            if (line.empty()) continue;

            std::stringstream ss(line);
            int type;
            if (!(ss >> type))
                throw std::invalid_argument("Missing shape type");

            std::string data;
            std::getline(ss, data); // phần còn lại của dòng (có thể có space đầu)
            Shape* shape = createShape(type, data);
            shapes.push_back(shape);
        }
        catch (const std::exception& e) {
            std::cerr << "Error parsing line: " << line << "\n";
            std::cerr << "Reason: " << e.what() << "\n";
        }
    }

    return shapes;
}

void ShapeFactory::saveShapesToFile(
    const std::string& filename,
    const std::vector<Shape*>& shapes) {

    std::ofstream file(filename);
    if (!file.is_open())
        throw std::runtime_error("Cannot write file: " + filename);

    for (const auto& s : shapes) {
        file << s->type() << " " << s->toString() << "\n";
    }
}