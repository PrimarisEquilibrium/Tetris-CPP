#include "SFML/Graphics.hpp"
#include <iostream>

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

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::Event e;
    sf::Clock clock; // Starts the clock

    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        std::cout << "Fps: " << getFps(clock) << std::endl;
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}