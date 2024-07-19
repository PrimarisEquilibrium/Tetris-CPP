#include "SFML/Graphics.hpp"

float getFps(sf::Clock& clock)
{
    float currentTime = clock.restart().asSeconds();
    float fps = 1.0f / currentTime;
    return fps;
}

sf::RectangleShape createRect(float x, float y, float width, float height, sf::Color color)
{
    sf::RectangleShape rect(sf::Vector2f(width, height));
    rect.setFillColor(color);
    rect.setPosition(x, y);
    return rect;
}