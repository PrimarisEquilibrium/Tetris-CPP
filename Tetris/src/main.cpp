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

    // The relative position (to the origin) of the tiles that make up the tetromino.
    std::vector<Point> tiles;

public:
    // Constructor
    Tetromino(Block type, Point position, std::vector<Point> tiles) :
        type(type), position(position), tiles(tiles) {}

    
    void rotateClockwise()
    {
        tiles = rotatePoints(tiles, origin, degToRad(-90));
    }

    void rotateCounterClockwise()
    {
        tiles = rotatePoints(tiles, origin, degToRad(90));
    }

    void draw(sf::RenderWindow& window)
    {
        for (int i = 0; i < tiles.size(); i++)
        {
            Point tile = tiles[i];
            Point absTilePos = position + tile;
            sf::RectangleShape tileRect = makeRectOnGrid(absTilePos, sf::Color::Yellow);
            window.draw(tileRect);
        }
    }
};

int main()
{   
    // SFML variables
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML window");
    sf::Clock clock;

    // Forces the window to run at 60fps max
    window.setFramerateLimit(60);

    std::map<Block, std::vector<Point>> blockShapes;

    Point position(2, 2);
    std::vector<Point> tiles = { {-1, 0}, {0, 0}, {1, 0}, {-1, 1} };
    Tetromino sampleTetromino(Block::L, position, tiles);

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

        // End the current frame
        window.display();
    }

    return 0;
}