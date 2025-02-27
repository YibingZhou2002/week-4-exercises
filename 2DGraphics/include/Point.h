#pragma once

class Point {
public:
    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    double getX() const { return x; }
    double getY() const { return y; }
    
    double distanceSquared(const Point& other) const {
        double dx = x - other.x;
        double dy = y - other.y;
        return dx*dx + dy*dy;
    }
    
private:
    double x;
    double y;
};
