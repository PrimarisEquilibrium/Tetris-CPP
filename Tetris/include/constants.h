#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "SFML/Graphics.hpp"

// Tetris grid dimension
const int rows = 16;
const int cols = 10;
const float gridBorder = 1.f;

// Tile size of each square on the grid
const int tileSize = 50;

// Window dimensions
const int width = cols * tileSize;
const int height = rows * tileSize;

// Colors
const sf::Color bgColor(40, 40, 43);
const sf::Color primaryColor(61, 61, 64);

#endif CONSTANTS_H