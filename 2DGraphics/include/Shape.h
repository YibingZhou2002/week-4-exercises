#pragma once
#include "Point.h"
#include "Color.h"

class Shape {
public:
    Shape(const Point& center, const Color& color) 
        : center(center), color(color), velocityX(0), velocityY(0) {}
    virtual ~Shape() = default;
    
    virtual bool contains(const Point& point) const = 0;
    
    const Point& getCenter() const { return center; }
    const Color& getColor() const { return color; }
    
    // Set velocity for animation
    void setVelocity(double vx, double vy) {
        velocityX = vx;
        velocityY = vy;
    }
    
    // Update position based on velocity and time step
    virtual void update(double dt) {
        center = Point(center.getX() + velocityX * dt, 
                      center.getY() + velocityY * dt);
        
        // Bounce off screen boundaries (assuming screen is 600x400)
        handleBoundaryCollision(600, 400);
    }
    
    // Handle boundary collision with bounce effect
    virtual void handleBoundaryCollision(int screenWidth, int screenHeight) = 0;
    
protected:
    Point center;
    Color color;
    double velocityX;
    double velocityY;
};

class Circle : public Shape {
public:
    Circle(const Point& center, double radius, const Color& color) 
        : Shape(center, color), radius(radius) {}
    
    bool contains(const Point& point) const override {
        return center.distanceSquared(point) <= radius * radius;
    }
    
    void handleBoundaryCollision(int screenWidth, int screenHeight) override {
        double x = center.getX();
        double y = center.getY();
        
        // Left or right boundary collision
        if (x - radius < 0 || x + radius > screenWidth) {
            velocityX = -velocityX; // Reverse x direction
            // Adjust position to prevent sticking to boundary
            if (x - radius < 0) {
                center = Point(radius, y);
            } else if (x + radius > screenWidth) {
                center = Point(screenWidth - radius, y);
            }
        }
        
        // Top or bottom boundary collision
        if (y - radius < 0 || y + radius > screenHeight) {
            velocityY = -velocityY; // Reverse y direction
            // Adjust position to prevent sticking to boundary
            if (y - radius < 0) {
                center = Point(x, radius);
            } else if (y + radius > screenHeight) {
                center = Point(x, screenHeight - radius);
            }
        }
    }
    
    double getRadius() const { return radius; }
    
private:
    double radius;
};

class Rectangle : public Shape {
public:
    Rectangle(const Point& center, double width, double height, const Color& color) 
        : Shape(center, color), width(width), height(height) {}
    
    bool contains(const Point& point) const override {
        double halfWidth = width / 2;
        double halfHeight = height / 2;
        
        double x = point.getX();
        double y = point.getY();
        double cx = center.getX();
        double cy = center.getY();
        
        return (x >= cx - halfWidth) && (x <= cx + halfWidth) && 
               (y >= cy - halfHeight) && (y <= cy + halfHeight);
    }
    
    void handleBoundaryCollision(int screenWidth, int screenHeight) override {
        double x = center.getX();
        double y = center.getY();
        double halfWidth = width / 2;
        double halfHeight = height / 2;
        
        // Left or right boundary collision
        if (x - halfWidth < 0 || x + halfWidth > screenWidth) {
            velocityX = -velocityX; // Reverse x direction
            // Adjust position to prevent sticking to boundary
            if (x - halfWidth < 0) {
                center = Point(halfWidth, y);
            } else if (x + halfWidth > screenWidth) {
                center = Point(screenWidth - halfWidth, y);
            }
        }
        
        // Top or bottom boundary collision
        if (y - halfHeight < 0 || y + halfHeight > screenHeight) {
            velocityY = -velocityY; // Reverse y direction
            // Adjust position to prevent sticking to boundary
            if (y - halfHeight < 0) {
                center = Point(x, halfHeight);
            } else if (y + halfHeight > screenHeight) {
                center = Point(x, screenHeight - halfHeight);
            }
        }
    }
    
    double getWidth() const { return width; }
    double getHeight() const { return height; }
    
private:
    double width;
    double height;
};
