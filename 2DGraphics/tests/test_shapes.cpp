#include "../include/Shape.h"
#include <cassert>
#include <iostream>
#include <string>

// A simple test framework - corrected macro implementation
#define TEST(name) \
    std::cout << "Running test: " << #name << "... "; \
    do { \
        test_##name(); \
        std::cout << "PASSED" << std::endl; \
    } while(0); \
    void test_##name()

int main() {
    std::cout << "Running tests for 2D Graphics Library" << std::endl;
    
    // Function declarations
    void test_circle_contains();
    void test_rectangle_contains();
    void test_shape_movement();
    void test_boundary_collision();
    
    // Run tests
    std::cout << "Running test: circle_contains... ";
    test_circle_contains();
    std::cout << "PASSED" << std::endl;
    
    std::cout << "Running test: rectangle_contains... ";
    test_rectangle_contains();
    std::cout << "PASSED" << std::endl;
    
    std::cout << "Running test: shape_movement... ";
    test_shape_movement();
    std::cout << "PASSED" << std::endl;
    
    std::cout << "Running test: boundary_collision... ";
    test_boundary_collision();
    std::cout << "PASSED" << std::endl;
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}

// Test function implementations
void test_circle_contains() {
    Circle circle(Point(100, 100), 50, Color(255, 0, 0));
    
    // Points inside the circle
    assert(circle.contains(Point(100, 100)) == true);  // Center
    assert(circle.contains(Point(120, 120)) == true);  // Inside
    assert(circle.contains(Point(100, 150)) == true);  // On edge
    
    // Points outside the circle
    assert(circle.contains(Point(200, 200)) == false);
    assert(circle.contains(Point(151, 100)) == false);
}

void test_rectangle_contains() {
    Rectangle rect(Point(200, 150), 100, 80, Color(0, 255, 0));
    
    // Points inside the rectangle
    assert(rect.contains(Point(200, 150)) == true);  // Center
    assert(rect.contains(Point(220, 160)) == true);  // Inside
    assert(rect.contains(Point(250, 150)) == true);  // On edge
    
    // Points outside the rectangle
    assert(rect.contains(Point(300, 300)) == false);
    assert(rect.contains(Point(251, 191)) == false);
}

void test_shape_movement() {
    Circle circle(Point(100, 100), 20, Color(255, 0, 0));
    
    // Set velocity and update
    circle.setVelocity(10, 5);
    circle.update(1.0);  // Update for 1 second
    
    // Check new position
    assert(circle.getCenter().getX() == 110);
    assert(circle.getCenter().getY() == 105);
}

void test_boundary_collision() {
    // Circle collision test
    Circle circle(Point(590, 100), 20, Color(255, 0, 0));
    circle.setVelocity(20, 0);  // Moving right
    circle.update(1.0);
    
    // Should have bounced off the right wall
    assert(circle.getCenter().getX() < 590);
    assert(circle.getCenter().getY() == 100);
    
    // Rectangle collision test
    Rectangle rect(Point(50, 10), 60, 40, Color(0, 255, 0));
    rect.setVelocity(0, -20);  // Moving up
    rect.update(1.0);
    
    // Should have bounced off the top wall
    assert(rect.getCenter().getX() == 50);
    assert(rect.getCenter().getY() > 10);
}
