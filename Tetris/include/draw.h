#ifndef DRAW_H
#define DRAW_H

/**
 * @brief Draws the rows by cols Tetris guide grid.
 * @param window An SFML window.
 */
void drawGrid(sf::RenderWindow& window);

/**
 * @brief Creates a sf::RectangleShape that fits onto the grid.
 * @note X needs to be between 0 - cols; Y needs to be between 0 - rows;
 * @param x     The x-position of the rect.
 * @param y     The y-position of the rect.
 * @param color The color of the rect.
 * @return The RectangleShape object.
 */
sf::RectangleShape makeRectOnGrid(float x, float y, sf::Color color);

/**
 * @brief Draws each tile contained within the given grid.
 * @param window An SMFL window.
 * @param grid   The grid containing tetromino tiles.
 */
void drawTiles(sf::RenderWindow& window, std::vector<std::vector<Block>>& grid);

#endif