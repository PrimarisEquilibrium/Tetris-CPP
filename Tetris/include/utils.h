#ifndef UTILS_H
#define UTILS_H

#include "types.h"
#include "SFML/Graphics.hpp"

/**
 * @brief Returns the FPS of the window.
 * @param clock an SFML clock.
 * @return The FPS of the window as a float.
 */
float getFps(sf::Clock& clock);

/**
 * @brief Produces a simple RectangleShape object.
 * @param point      The position of the rect.   
 * @param rectWidth  The width of the rect.
 * @param rectHeight The height of the rect.
 * @param color      The color of the rect.
 * @return The RectangleShape object.
 */
sf::RectangleShape createRect(Point point, float rectWidth, float rectHeight, sf::Color color);

/**
 * @brief Rotates a given point around a given pivot point.
 * @param point       The point to rotate.
 * @param pivot       The pivot point.
 * @param angleInRads Angle to rotate by.
 * @returns The new rotated point.
 */
Point rotatePoint(Point point, Point pivot, float angleInRads);

/**
 * @brief Rotates a vector of points around a given pivot point.
 * @param tiles       The points to rotate.
 * @param pivot       The pivot point.
 * @param angleInRads Angle to rotate by.
 * @returns The new vector of rotated points.
 */ 
std::vector<Point> rotatePoints(std::vector<Point> tiles, Point pivot, float angleInRads);

/**
 * @brief Converts from degrees to radians.
 * @param deg The degree value to convert.
 * @return The radian equivalent to the passed degree.
 */
float degToRad(float deg);

/**
 * @brief Randomly selects a value from the vector.
 * @param vector The vector to randomly select a value from.
 * @return The randomly selected value.
 */
template <typename T>
T randomVectorChoice(const std::vector<T>& vector)
{
    size_t N = vector.size();
    int randomVectorIndex = rand() % N;
    return vector[randomVectorIndex];
}

#endif