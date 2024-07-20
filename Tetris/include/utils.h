#ifndef UTILS_H
#define UTILS_H

#include "SFML/Graphics.hpp"

/**
 * @brief Returns the FPS of the window.
 * @param clock an SFML clock.
 * @return The FPS of the window as a float.
 */
float getFps(sf::Clock& clock);

/**
 * @brief Produces a simple RectangleShape object.
 * @param x      The x-coordinate of the rect.
 * @param y      The y-coordinate of the rect.
 * @param width  The width of the rect.
 * @param height The height of the rect.
 * @param color  The color of the rect.
 * @return The RectangleShape object.
 */
sf::RectangleShape createRect(float x, float y, float width, float height, sf::Color color);

/**
 * @brief Rotates a given point around a given pivot point.
 * @param cx          Pivot x-coordinate.
 * @param cy          Pivot y-coordinate.
 * @param angleInRads Angle to rotate by (positive counterclockwise, negative clockwise)
 * @param x           Point to rotate x-coordinate.
 * @param y           Point to rotate y-coordinate.
 * @returns A pair containing the x and y coordinates of the new rotated point.
 */
std::pair<float, float> rotatePoint(float cx, float cy, float angleInRads, float x, float y);

/**
 * @brief Converts from degrees to radians.
 * @param deg The degree value to convert.
 * @return The radian equivalent to the passed degree.
 */
float degToRad(float deg);

#endif