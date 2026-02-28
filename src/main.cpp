#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "../include/Bat.h"
#include "../include/Ball.h"

using namespace sf;

std::vector<RectangleShape> generateBlocks(int rows, int cols, float tileWidth, float tileHeight, float spacing, float marginX)
{
    std::vector<RectangleShape> blocks;
    for (int y = 0; y < rows; ++y)
    {
        for (int x = 0; x < cols; ++x)
        {
            RectangleShape tile(Vector2f(tileWidth, tileHeight));
            tile.setFillColor(Color(0, 0, 139));
            tile.setOutlineThickness(2);
            tile.setOutlineColor(Color::Black);
            float posX = marginX + x * (tileWidth + spacing);
            float posY = spacing + y * (tileHeight + spacing);
            tile.setPosition({posX, posY});
            blocks.push_back(tile);
        }
    }
    return blocks;
}

void handleBallObstacleCollision(Ball &ball, const RectangleShape &obstacle)
{
    FloatRect ballBounds = ball.getShape().getGlobalBounds();
    FloatRect obsBounds = obstacle.getGlobalBounds();

    float dx = (ballBounds.position.x + ballBounds.size.x / 2) - (obsBounds.position.x + obsBounds.size.x / 2);
    float dy = (ballBounds.position.y + ballBounds.size.y / 2) - (obsBounds.position.y + obsBounds.size.y / 2);

    if (std::abs(dx) > std::abs(dy))
        ball.reverseX();
    else
        ball.reverseY();
}

int main()
{
    RenderWindow window(VideoMode({960, 540}), "Pong Game...!!!");
    Vector2u windowSize = window.getSize();
    int windowWidth = windowSize.x;
    int windowHeight = windowSize.y;
    int halfWidth = windowWidth / 2;
    int halfHeight = windowHeight / 2;

    Bat bat(halfWidth, 520);
    Ball ball(10.0f, halfWidth, -100);
    Clock clock;

    int score = 0, lives = 3;
    bool gameOver = false, acceptInput = false;

    Font font;
    if (!font.openFromFile("../assets/fonts/KOMIKAP_.ttf"))
        return -1;

    Text hud(font), gameOverText(font), messageText(font), pauseText(font);
    hud.setCharacterSize(30);
    hud.setFillColor(Color::White);
    hud.setPosition({30.f, 265.f});
    gameOverText.setCharacterSize(30);
    gameOverText.setFillColor(Color::Cyan);
    gameOverText.setString("Game Over ! Press Enter to Restart");
    messageText.setCharacterSize(30);
    messageText.setFillColor(Color::Cyan);
    messageText.setString("Press Enter to Start the Game !");
    pauseText.setCharacterSize(70);
    pauseText.setFillColor(Color::Red);
    pauseText.setString("Game Paused...");

    FloatRect bounds;

    bounds = gameOverText.getLocalBounds();
    gameOverText.setOrigin({bounds.position.x + bounds.size.x / 2.0f, bounds.position.y + bounds.size.y / 2.0f});
    gameOverText.setPosition({windowWidth / 2.0f, windowHeight / 2.0f});

    bounds = messageText.getLocalBounds();
    messageText.setOrigin({bounds.position.x + bounds.size.x / 2.0f, bounds.position.y + bounds.size.y / 2.0f});
    messageText.setPosition({windowWidth / 2.0f, windowHeight / 2.0f});

    bounds = pauseText.getLocalBounds();
    pauseText.setOrigin({bounds.position.x + bounds.size.x / 2.0f, bounds.position.y + bounds.size.y / 2.0f});
    pauseText.setPosition({windowWidth / 2.0f, windowHeight / 2.0f});

    Texture bgTexture;
    if (!bgTexture.loadFromFile("../assets/images/background.jpg"))
        return -1;
    Sprite bgSprite(bgTexture);
    Vector2u texSize = bgTexture.getSize();
    bgSprite.setScale({float(windowWidth) / texSize.x, float(windowHeight) / texSize.y});

    const float tileWidth = 100.0f, tileHeight = 30.0f, spacing = 5.0f;
    int tilesPerRow = (windowWidth + spacing) / (tileWidth + spacing);
    int tilesPerColumn = (halfHeight + spacing) / (tileHeight + spacing);
    float totalTilesWidth = tilesPerRow * tileWidth + (tilesPerRow - 1) * spacing;
    float marginX = (windowWidth - totalTilesWidth) / 2.0f;

    std::vector<RectangleShape> blocks = generateBlocks(tilesPerColumn, tilesPerRow, tileWidth, tileHeight, spacing, marginX);

    RectangleShape obstacle1, obstacle2;
    for (auto *obs : {&obstacle1, &obstacle2})
    {
        obs->setSize(Vector2f(tileWidth, tileHeight));
        obs->setFillColor(Color(128, 128, 128));
        obs->setOutlineThickness(5);
        obs->setOutlineColor(Color::Black);
        obs->setOrigin({tileWidth / 2.0f, tileHeight / 2.0f});
    }
    obstacle1.setPosition({halfWidth / 2.0f, (halfHeight / 2.0f) + halfHeight});
    obstacle2.setPosition({(halfWidth / 2.0f) + halfWidth, (halfHeight / 2.0f) + halfHeight});

    while (window.isOpen())
    {
        while (const auto event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>() || Keyboard::isKeyPressed(Keyboard::Key::Escape))
                window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
            acceptInput = true;

        if (!gameOver && acceptInput)
        {
            ball.start();

            if (Keyboard::isKeyPressed(Keyboard::Key::Left))
                bat.moveLeft();
            else
                bat.stopLeft();
            if (Keyboard::isKeyPressed(Keyboard::Key::Right))
                bat.moveRight();
            else
                bat.stopRight();

            Time dt = clock.restart();
            bat.update(dt);
            ball.update(dt.asSeconds(), window);

            if (ball.getShape().getGlobalBounds().findIntersection(obstacle1.getGlobalBounds()))
                handleBallObstacleCollision(ball, obstacle1);
            if (ball.getShape().getGlobalBounds().findIntersection(obstacle2.getGlobalBounds()))
                handleBallObstacleCollision(ball, obstacle2);

            for (auto it = blocks.begin(); it != blocks.end();)
            {
                if (ball.getShape().getGlobalBounds().findIntersection(it->getGlobalBounds()))
                {
                    ball.reverseY();
                    it = blocks.erase(it);
                    score++;
                }
                else
                    ++it;
            }

            if (ball.getShape().getGlobalBounds().findIntersection(bat.getShape().getGlobalBounds()))
                ball.reverseY();

            if (ball.getShape().getPosition().y > windowHeight)
            {
                lives--;
                ball.reset(halfWidth, 0);
                if (lives == 0)
                    gameOver = true;
            }

            std::stringstream ss;
            ss << "Score: " << score << "  Lives: " << lives;
            hud.setString(ss.str());
        }
        else if (acceptInput && gameOver)
        {
            if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
            {
                lives = 3;
                score = 0;
                gameOver = false;
                blocks = generateBlocks(tilesPerColumn, tilesPerRow, tileWidth, tileHeight, spacing, marginX);
                ball.reset(halfWidth, -100);
            }
        }

        window.clear();
        window.draw(bgSprite);

        if (acceptInput)
        {
            if (gameOver)
                window.draw(gameOverText);
            else
            {
                for (const auto &tile : blocks)
                    window.draw(tile);
                window.draw(hud);
                window.draw(bat.getShape());
                window.draw(ball.getShape());
                window.draw(obstacle1);
                window.draw(obstacle2);
            }
        }
        else
            window.draw(messageText);

        window.display();
    }

    return 0;
}
