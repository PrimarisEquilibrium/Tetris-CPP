#include "utils.h"
#include "constants.h"

void drawGrid(sf::RenderWindow& window)
{
    // Row and col start at index 1 to prevent drawing an extra border on the left sideo of the window

    // Horizontal lines
    for (int row = 1; row < rows; row++)
    {
        float yPoint = static_cast<float>(row * tileSize);
        Point linePosition(0.f, yPoint);
        sf::RectangleShape tileLine = createRect(linePosition, static_cast<float>(width), gridBorder, primaryColor);
        window.draw(tileLine);
    }

    // Vertical lines
    for (int col = 1; col < cols; col++)
    {
        float xPoint = static_cast<float>(col * tileSize);
        Point linePosition(xPoint, 0.f);
        sf::RectangleShape tileLine = createRect(linePosition, gridBorder, static_cast<float>(height), primaryColor);
        window.draw(tileLine);
    }
}

sf::RectangleShape makeRectOnGrid(Point point, sf::Color color)
{
    // operator+ gridBorder: Offset x & y to the right to fit
    Point gridScaledPoint(point.x * tileSize + gridBorder, point.y * tileSize + gridBorder);

    // operator- gridBorder: Offset dimensions to the left to fit
    float tileDimension = tileSize - gridBorder;

    return createRect(gridScaledPoint, tileDimension, tileDimension, color);
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
                color = orange;
                break;
            case Block::O:
                color = sf::Color::Yellow;
                break;
            case Block::S:
                color = sf::Color::Green;
                break;
            case Block::T:
                color = purple;
                break;
            case Block::Z:
                color = sf::Color::Red;
                break;
            }

            float fcol = static_cast<float>(col);
            float frow = static_cast<float>(row);
            Point tilePosition(fcol, frow);
            sf::RectangleShape rect = makeRectOnGrid(tilePosition, color);
            window.draw(rect);
        }
    }
}