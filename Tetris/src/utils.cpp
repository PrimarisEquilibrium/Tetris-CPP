#include "constants.h"
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
    rect.setPosition(x, y);
    rect.setFillColor(color);
    return rect;
}

std::pair<float, float> rotatePoint(float cx, float cy, float angleInRads, float x, float y)
{
    float s = sin(angleInRads);
    float c = cos(angleInRads);

    // Translate the point back to 0, 0 (the origin)
    x -= cx;
    y -= cx;

    // Use a rotation matrix to rotate a point around the given angle
    float xNew = x * c - y * s;
    float yNew = x * s + y * c;

    // Translate the point back to the pivot
    x = xNew + cx;
    y = yNew + cy;

    return std::make_pair(x, y);
}

float degToRad(float deg)
{
    return deg * (PI / 180);
}