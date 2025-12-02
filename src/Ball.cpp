#include "../include/Ball.h"

Ball::Ball(float radius, float startX, float startY)
    : speedX(200.0f), speedY(200.0f), isMoving(false)
{
    ballShape.setRadius(radius);
    ballShape.setFillColor(sf::Color::White);
    ballShape.setPosition(startX, startY);
}

void Ball::start()
{
    isMoving = true;
}
void Ball::stop()
{
    isMoving = false;
}

void Ball::update(float dt, const sf::RenderWindow &window)
{
    if (!isMoving)
        return;

    sf::Vector2f pos = ballShape.getPosition();
    pos.x += speedX * dt;
    pos.y += speedY * dt;

    if (pos.x <= 0 || pos.x + ballShape.getRadius() * 2 >= window.getSize().x)
    {
        reverseX();
    }

    if (pos.y <= 0)
    {
        reverseY();
    }

    ballShape.setPosition(pos);
}

void Ball::reverseX()
{
    speedX = -speedX;
}

void Ball::reverseY()
{
    speedY = -speedY;
}

void Ball::reset(float startX, float startY)
{
    ballShape.setPosition(startX, startY);
    isMoving = false;
}

const sf::CircleShape &Ball::getShape() const
{
    return ballShape;
}
