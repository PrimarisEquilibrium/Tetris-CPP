#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "types.h"
#include "SFML/Graphics.hpp"
#include <cmath>

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

const float PI = std::atan(1.f) * 4.f;

// The origin of a standard graph
inline const Point defaultOrigin(0, 0);

// Custom colors
inline const sf::Color orange(255, 165, 0);
inline const sf::Color purple(153, 50, 204);

#endif