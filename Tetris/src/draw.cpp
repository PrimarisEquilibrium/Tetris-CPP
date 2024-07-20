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

void drawTiles(sf::RenderWindow& window, std::vector<std::vector<Block>>& grid)
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            Block blockType = grid[row][col];

            // Skip drawing if the tile is empty
            if (blockType == Empty)
                continue;

            // Assign a color based on the type of block occupies the grid tile.
            sf::Color color{};
            switch (blockType)
            {
            case Block::I:
                color = sf::Color::Cyan;
                break;
            case Block::J:
                color = sf::Color::Blue;
                break;
            case Block::L:
                color = sf::Color(255, 165, 0); // Orange
                break;
            case Block::O:
                color = sf::Color::Yellow;
                break;
            case Block::S:
                color = sf::Color::Green;
                break;
            case Block::T:
                color = sf::Color(153, 50, 204); // Purple
                break;
            case Block::Z:
                color = sf::Color::Red;
                break;
            }

            float fcol = static_cast<float>(col);
            float frow = static_cast<float>(row);
            sf::RectangleShape rect = makeRectOnGrid(fcol, frow, color);
            window.draw(rect);
        }
    }
}