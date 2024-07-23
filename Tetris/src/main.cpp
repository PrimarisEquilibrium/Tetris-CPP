#include "types.h"
#include "utils.h"
#include "constants.h"
#include "draw.h"
#include "tetromino.h"

#include "SFML/Graphics.hpp"

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <stdexcept>
#include <cmath>

// 2D Vector containing the state of all tiles on the Tetris grid
// Initially fills it with Empty
std::vector<std::vector<Block>> grid(rows, std::vector<Block>(cols, Block::Empty));

int main()
{   
    // SFML variables
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML window");
    sf::Clock clock;

    // Forces the window to run at 60fps max
    window.setFramerateLimit(60);

    Tetromino* tetrominoObj = makeTetromino(Point(2, 2), Block::I);
    Tetromino sampleTetromino = *tetrominoObj;
    sampleTetromino.updateToGrid(grid);

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

        // sampleTetromino.draw(window);
        // sampleTetromino.drawOrigin(window);

        // End the current frame
        window.display();
    }

    delete tetrominoObj;

    return 0;
}