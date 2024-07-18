#include "SFML/Graphics.hpp"
#include <iostream>
#include <vector>

/**
 * @brief Gets the FPS of the window.
 * @param clock an SFML clock.
 * @return The FPS of the window as a float.
 */
float getFps(sf::Clock& clock)
{
    float currentTime = clock.restart().asSeconds();
    float fps = 1.0f / currentTime;
    return fps;
}

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

// Tetris grid dimension
const int rows = 16;
const int cols = 10;

// Tile size of each square on the grid
const int tileSize = 50;

// Window dimensions
const int width = cols * tileSize;
const int height = rows * tileSize;

// Colors
const sf::Color bgColor(40, 40, 43);
const sf::Color primaryColor(61, 61, 64);

// 2D Vector containing the state of all tiles on the Tetris grid
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

        // End the current frame
        window.display();
    }

    return 0;
}