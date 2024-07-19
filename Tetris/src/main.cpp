#include "utils.h"
#include "constants.h"
#include "draw.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

// The different types of tetrominoes
enum Block
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

    // Run the program as long as the window is open
    while (window.isOpen())
    {
        std::cout << "Fps: " << getFps(clock) << std::endl;

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

        sf::RectangleShape rect = makeRectOnGrid(6, 0, sf::Color::Cyan);
        window.draw(rect);

        // End the current frame
        window.display();
    }

    return 0;
}