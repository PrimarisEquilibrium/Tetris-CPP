#ifndef TETROMINO_H
#define TETROMINO_H

#include "types.h"
#include "SFML/Graphics.hpp"
#include <vector>

/**
 * @class Tetromino
 * @brief Represents a tetromino shape in a Tetris playing field.
 *
 * This class handles the properties and operations of a Tetris piece.
 */
class Tetromino
{
private:
    /** @brief The type of Tetromino represented as a Block (I, J, Z, etc.)*/
    Block type;

    /** @brief The absolute position of a tetromino (based off the origin) */
    Point position;

    /** @brief The origin point of the tetromino (required for irregular shapes, i.e. I & O) */
    Point origin;

    /** @brief The relative position(to the origin) of the tiles that make up the tetromino. */
    std::vector<Point> tiles;

public:
    // Constructor
    Tetromino(Block type, Point position, Point origin, std::vector<Point> tiles);

    Point getOrigin();

    Point getPosition();

    void rotateClockwise();

    void rotateCounterClockwise();

    void shiftLeft();

    void shiftRight();

    void shiftDown();

    // Places the corresponding tiles onto the Tetris grid 2D Vector
    void updateToGrid(std::vector<std::vector<Block>>& grid);

    // Draws the origin point onto the Tetris grid
    void drawOrigin(sf::RenderWindow& window);
};

/**
 * @brief Creates a Tetromino class instance.
 * @param initialPos The position to create it at.
 * @param type       The type of block the tetromino will be.
 */
Tetromino makeTetromino(Point initialPos, Block type);

#endif