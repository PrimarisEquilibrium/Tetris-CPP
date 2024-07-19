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

#endif