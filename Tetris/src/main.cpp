#include "utils.h"
#include "constants.h"
#include "draw.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <utility>

// 2D Vector containing the state of all tiles on the Tetris grid
// Initially fills it with Empty
std::vector<std::vector<Block>> grid(rows, std::vector<Block>(cols, Block::Empty));

class Tetromino
{
private:
    // Type of tetromino
    Block type;

    // The absolute position of a tetromino (from the center)
    Point position;

    // The origin point of the tetromino (required for irregular shapes, i.e. I & O)
    Point origin;

    // The relative position (to the origin) of the tiles that make up the tetromino.
    std::vector<Point> tiles;

public:
    // Constructor
    Tetromino(Block type, Point position, Point origin, std::vector<Point> tiles) :
        type(type), position(position), origin(origin), tiles(tiles) {}

    Point getOrigin()
    {
        return origin;
    }
    
    void rotateClockwise()
    {
        tiles = rotatePoints(tiles, origin, degToRad(90));
    }

    void rotateCounterClockwise()
    {
        tiles = rotatePoints(tiles, origin, degToRad(-90));
    }

    void draw(sf::RenderWindow& window)
    {
        for (int i = 0; i < tiles.size(); i++)
        {
            Point tile = tiles[i];
            Point absTilePos = position + tile;
            sf::RectangleShape tileRect = makeRectOnGrid(absTilePos, sf::Color::Cyan);
            window.draw(tileRect);
        }
    }
};

Tetromino makeTetromino(Point initialPos, Block type)
{
    Point origin = defaultOrigin;
    std::vector<Point> tiles{};

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

int main()
{   
    // SFML variables
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML window");
    sf::Clock clock;

    // Forces the window to run at 60fps max
    window.setFramerateLimit(60);

    std::map<Block, std::vector<Point>> blockShapes;

    Point position(2, 2);
    Tetromino sampleTetromino = makeTetromino(position, Block::I);
    sampleTetromino.rotateClockwise();

    // Run the program as long as the window is open
    while (window.isOpen())
    {
        // std::cout << "Fps: " << getFps(clock) << std::endl;

        // Check for any new events since the last iteration of the loop
        sf::Event e;
        while (window.pollEvent(e))
        {
            // Compare the received event with the "closing requested" event
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // Clear the window with matte black color
        window.clear(bgColor);

        drawGrid(window);
        drawTiles(window, grid);

        sampleTetromino.draw(window);
        window.draw(makeRectOnGrid(sampleTetromino.getOrigin() + position, sf::Color::Red));

        // End the current frame
        window.display();
    }

    return 0;
}