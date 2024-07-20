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

int main()
{   
    // SFML variables
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML window");
    sf::Clock clock;

    // Forces the window to run at 60fps max
    window.setFramerateLimit(60);
    
    grid[1][1] = Block::J;

    Point point(1.f, 2.f);
    Point pivot(2.f, 2.f);
    Point newPoint = rotatePoint(point, pivot, degToRad(-90));
    std::cout << newPoint.x << ", " << newPoint.y << std::endl;

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

        // End the current frame
        window.display();
    }

    return 0;
}