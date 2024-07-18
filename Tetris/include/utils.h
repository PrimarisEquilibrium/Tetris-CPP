#ifndef UTILS_H
#define UTILS_H

#include "SFML/Graphics.hpp"

/**
 * @brief Returns the FPS of the window.
 * @param clock an SFML clock.
 * @return The FPS of the window as a float.
 */
float getFps(sf::Clock& clock);

#endif