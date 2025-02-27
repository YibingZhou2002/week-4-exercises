#pragma once
#include <cstdint>

class Color {
public:
    Color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0) : r(r), g(g), b(b) {}
    
    uint8_t getR() const { return r; }
    uint8_t getG() const { return g; }
    uint8_t getB() const { return b; }
    
private:
    uint8_t r, g, b;
};
