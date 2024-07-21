#ifndef TYPES_H
#define TYPES_H

/** @brief A coordinate value containing an x and y. */
struct Point
{
    float x;
    float y;

    Point(float x, float y) : x(x), y(y) {}

public:
    // Coordinate addition
    Point operator+(const Point& other)
    {
        return Point(x + other.x, y + other.y);
    }
};

// The different types of tetrominoes
constexpr enum Block
{
    Empty,
    I,
    J,
    L,
    O,
    S,
    T,
    Z
};

#endif
