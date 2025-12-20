// Development scratch program preserved in examples/
#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include "../include/Bat.h"
#include "../include/Ball.h"

using namespace sf;

void handleBallObstacleCollision(Ball &ball, const RectangleShape &obstacle)
{
    FloatRect ballBounds = ball.getShape().getGlobalBounds();
    FloatRect obsBounds = obstacle.getGlobalBounds();

    float dx = (ballBounds.left + ballBounds.width / 2) - (obsBounds.left + obsBounds.width / 2);
    float dy = (ballBounds.top + ballBounds.height / 2) - (obsBounds.top + obsBounds.height / 2);

    if (std::abs(dx) > std::abs(dy))
        ball.reverseX();
    else
        ball.reverseY();
}

int main()
{
    VideoMode vm(960, 540);
    RenderWindow window(vm, "Pong - Dev");

    Vector2u windowSize = window.getSize();
    unsigned int windowWidth = windowSize.x;
    unsigned int windowHeight = windowSize.y;
    const int halfHeight = windowHeight / 2;
    const int halfWidth = windowWidth / 2;

    int score = 0;
    int lives = 3;
    bool gameOver = false, acceptInput = false;

    Bat bat(halfWidth, 520);
    Ball ball(10.0f, halfWidth, -100);

    Clock clock;

    Text hud;
    Font font;
    if (!font.loadFromFile("assets/fonts/KOMIKAP_.ttf"))
        return -1;
    hud.setFont(font);
    hud.setCharacterSize(30);
    hud.setFillColor(Color::White);
    hud.setPosition(30, 265);

    Texture BackgroundTexture;
    BackgroundTexture.loadFromFile("assets/images/background.jpg");
    Sprite BackgroundSprite(BackgroundTexture);
    Vector2u textureSize = BackgroundTexture.getSize();
    BackgroundSprite.setScale(float(windowWidth) / textureSize.x, float(windowHeight) / textureSize.y);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(BackgroundSprite);
        window.draw(hud);
        window.display();
    }

    return 0;
}
