#include "tetromino.h"
#include "types.h"
#include "utils.h"
#include "draw.h"
#include "constants.h"
#include <vector>

Tetromino::Tetromino(Block type, Point position, Point origin, std::vector<Point> tiles) :
    type(type), position(position), origin(origin), tiles(tiles) {}

Point Tetromino::getOrigin()
{
    return origin;
}

Point Tetromino::getPosition()
{
    return position;
}

void Tetromino::rotateClockwise()
{
    tiles = rotatePoints(tiles, origin, degToRad(90));
}

void Tetromino::rotateCounterClockwise()
{
    tiles = rotatePoints(tiles, origin, degToRad(-90));
}

void Tetromino::shiftRight()
{
    position = position + Point(1, 0);
}

void Tetromino::shiftLeft()
{
    position = position + Point(-1, 0);
}

void Tetromino::draw(sf::RenderWindow& window)
{
    for (const auto& tile : tiles)
    {
        Point absTilePos = position + tile;
        sf::RectangleShape tileRect = makeRectOnGrid(absTilePos, sf::Color::Cyan);
        window.draw(tileRect);
    }
}

Tetromino makeTetromino(Point initialPos, Block type)
{
    Point origin = defaultOrigin;
    std::vector<Point> tiles{};

    // Depending on tetromino the origin point and shape may change
    switch (type) {
    case Block::I:
        origin = Point(-0.5, -0.5);
        tiles = { {-2, -1}, {-1, -1}, {0, -1}, {1, -1} };
        break;
    case Block::J:
        tiles = { {-1, -1}, {-1, 0}, {0, 0}, {1, 0} };
        break;
    case Block::L:
        tiles = { {1, -1}, {-1, 0}, {0, 0}, {1, 0} };
        break;
    case Block::O:
        origin = Point(0.5, 0.5);
        tiles = { {0, 0}, {1, 0}, {0, 1}, {1, 1} };
        break;
    case Block::S:
        tiles = { {-1, 0}, {0, 0}, {0, -1}, {1, -1} };
        break;
    case Block::T:
        tiles = { {0, -1}, {-1, 0}, {0, 0}, {1, 0} };
        break;
    case Block::Z:
        tiles = { {-1, -1}, {0, -1}, {0, 0}, {1, 0} };
        break;
    default:
        throw std::runtime_error("makeTetromino() received an incorrect Block type");
    }

    return Tetromino(type, initialPos, origin, tiles);
}