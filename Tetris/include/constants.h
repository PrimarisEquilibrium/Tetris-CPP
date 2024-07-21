#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "utils.h"
#include "SFML/Graphics.hpp"

// Tetris grid dimension
inline constexpr int rows = 16;
inline constexpr int cols = 10;
inline constexpr float gridBorder = 2.f;

// Tile size of each square on the grid
inline constexpr int tileSize = 50;

// Window dimensions
inline constexpr int width = cols * tileSize;
inline constexpr int height = rows * tileSize;

// Colors
const sf::Color bgColor(40, 40, 43);
const sf::Color primaryColor(61, 61, 64);

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

const float PI = std::atan(1.f) * 4.f;

inline const Point origin(0, 0);

#endif