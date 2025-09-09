#include "Ball.h"

Ball::Ball(float radius, float startX, float startY)
    : speedX(200.0f), speedY(200.0f), isMoving(false)
{
    ballShape.setRadius(radius);
    ballShape.setFillColor(sf::Color::White);
    ballShape.setPosition(startX, startY);
}

// Start ball movement
void Ball::start()
{
    isMoving = true;
}
void Ball::stop()
{
    isMoving = false;
}

// Update ball movement
void Ball::update(float dt, const sf::RenderWindow &window)
{
    if (!isMoving)
        return; // Only move if started

    sf::Vector2f pos = ballShape.getPosition();
    pos.x += speedX * dt;
    pos.y += speedY * dt;

    // Ball collision with left or right wall
    if (pos.x <= 0 || pos.x + ballShape.getRadius() * 2 >= window.getSize().x)
    {
        reverseX();
    }

    // Ball collision with top wall
    if (pos.y <= 0)
    {
        reverseY();
    }

    ballShape.setPosition(pos);
}

// Reverse ball direction (horizontal)
void Ball::reverseX()
{
    speedX = -speedX;
}

// Reverse ball direction (vertical)
void Ball::reverseY()
{
    speedY = -speedY;
}

// Reset ball position
void Ball::reset(float startX, float startY)
{
    ballShape.setPosition(startX, startY);
    isMoving = false; // Stop movement until Enter is pressed again
}

// Get the shape for rendering
const sf::CircleShape &Ball::getShape() const
{
    return ballShape;
}
