#include <SFML/Graphics.hpp>
#include <cmath>

int main()
{
    const int windowWidth = 960;
    const int windowHeight = 540;
    const int halfHeight = windowHeight / 2;

    const float tileWidth = 100.0f;
    const float tileHeight = 30.0f;
    const float spacing = 5.0f;

    int tilesPerRow = static_cast<int>((windowWidth + spacing) / (tileWidth + spacing));
    int tilesPerColumn = static_cast<int>((halfHeight + spacing) / (tileHeight + spacing));

    float totalTilesWidth = tilesPerRow * tileWidth + (tilesPerRow - 1) * spacing;
    float marginX = (windowWidth - totalTilesWidth) / 2.0f;

    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Centered Tile Grid");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        window.clear(sf::Color::Black);

        for (int y = 0; y < tilesPerColumn; ++y)
        {
            for (int x = 0; x < tilesPerRow; ++x)
            {
                sf::RectangleShape tile(sf::Vector2f(tileWidth, tileHeight));
                tile.setFillColor(sf::Color::Yellow);

                float posX = marginX + x * (tileWidth + spacing);
                float posY = spacing + y * (tileHeight + spacing);
                tile.setPosition(posX, posY);

                window.draw(tile);
            }
        }

        window.display();
    }

    return 0;
}
