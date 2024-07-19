#include "utils.h"
#include "constants.h"

void drawGrid(sf::RenderWindow& window)
{
    // Row and col start at index 1 to prevent drawing an extra border on the left sideo of the window

    // Horizontal lines
    for (int row = 1; row < rows; row++)
    {
        sf::RectangleShape tileLine = createRect(
            0.f, static_cast<float>(row * tileSize), static_cast<float>(width), gridBorder, primaryColor
        );
        window.draw(tileLine);
    }

    // Vertical lines
    for (int col = 1; col < cols; col++)
    {
        sf::RectangleShape tileLine = createRect(
            static_cast<float>(col * tileSize), 0.f, gridBorder, static_cast<float>(height), primaryColor
        );
        window.draw(tileLine);
    }
}

sf::RectangleShape makeRectOnGrid(float x, float y, sf::Color color)
{
    return createRect(
        x * tileSize + gridBorder, // Offset x & y to the right to fit
        y * tileSize + gridBorder,
        tileSize - gridBorder,     // Offset dimensions to the left to fit
        tileSize - gridBorder,
        color
    );
}