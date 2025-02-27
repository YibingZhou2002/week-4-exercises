#include "../include/Scene.h"
#include <fstream>
#include <iostream>

// Simple PPM image format for output
bool Scene::saveImage(const std::string& filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Could not open " << filename << " for writing." << std::endl;
        return false;
    }
    
    // Write PPM header
    file << "P6\n" << width << " " << height << "\n255\n";
    
    // Write pixel data
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            // Convert screen coordinates to world coordinates
            // In this simple implementation, pixel (0,0) is at world coordinates (0,0)
            Point pixelPoint(x, y);
            Color pixelColor = getColorAt(pixelPoint);
            
            file.put(pixelColor.getR());
            file.put(pixelColor.getG());
            file.put(pixelColor.getB());
        }
    }
    
    return file.good();
}
