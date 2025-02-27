#pragma once
#include "Shape.h"
#include <vector>
#include <memory>
#include <string>
#include <functional>

class Scene {
public:
    Scene(int width, int height, const Color& background = Color(255, 255, 255)) 
        : width(width), height(height), backgroundColor(background), frameCount(0) {}
    
    void addShape(std::unique_ptr<Shape> shape) {
        shapes.push_back(std::move(shape));
    }
    
    Color getColorAt(const Point& point) const {
        // Iterate through shapes in reverse order (last added is on top)
        for (auto it = shapes.rbegin(); it != shapes.rend(); ++it) {
            if ((*it)->contains(point)) {
                return (*it)->getColor();
            }
        }
        return backgroundColor;
    }
    
    bool saveImage(const std::string& filename) const;
    
    // Update all shapes in the scene
    void update(double dt) {
        for (auto& shape : shapes) {
            shape->update(dt);
        }
    }
    
    // Animate the scene for a given duration with a specified frame rate
    void animate(double duration, int fps, const std::string& filenamePrefix) {
        double timeStep = 1.0 / fps;
        int totalFrames = static_cast<int>(duration * fps);
        
        for (int i = 0; i < totalFrames; i++) {
            frameCount++;
            update(timeStep);
            
            // Generate filename with leading zeros for proper sorting
            char filename[100];
            sprintf(filename, "%s_%04d.ppm", filenamePrefix.c_str(), frameCount);
            
            saveImage(filename);
        }
    }
    
    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getFrameCount() const { return frameCount; }
    
private:
    int width;
    int height;
    int frameCount;
    Color backgroundColor;
    std::vector<std::unique_ptr<Shape>> shapes;
};
