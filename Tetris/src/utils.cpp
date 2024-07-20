#include "utils.h"
#include "constants.h"
#include "SFML/Graphics.hpp"

float getFps(sf::Clock& clock)
{
    float currentTime = clock.restart().asSeconds();
    float fps = 1.0f / currentTime;
    return fps;
}

sf::RectangleShape createRect(Point point, float rectWidth, float rectHeight, sf::Color color)
{
    sf::RectangleShape rect(sf::Vector2f(rectWidth, rectHeight));
    rect.setPosition(point.x, point.y);
    rect.setFillColor(color);
    return rect;
}

Point rotatePoint(Point point, Point pivot, float angleInRads)
{
    float s = sin(angleInRads);
    float c = cos(angleInRads);

    // Translate the point back to 0, 0 (the origin)
    point.x -= pivot.x;
    point.y -= pivot.y;

    // Use a rotation matrix to rotate a point around the given angle
    float xNew = point.x * c - point.y * s;
    float yNew = point.x * s + point.y * c;

    // Translate the point back to the pivot
    point.x = xNew + pivot.x;
    point.y = yNew + pivot.y;

    return point;
}

float degToRad(float deg)
{
    return deg * (PI / 180);
}