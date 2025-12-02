#include "../include/Bat.h"

Bat::Bat(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;
    m_Shape.setSize(sf::Vector2f(50, 5));
    m_Shape.setFillColor(sf::Color::White);
    m_Shape.setPosition(m_Position);
}
sf::FloatRect Bat::getPosition()
{
    return m_Shape.getGlobalBounds();
}
sf::RectangleShape Bat::getShape()
{
    return m_Shape;
}
void Bat::start()
{
    isBatMove = true;
}
void Bat::stop()
{
    isBatMove = false;
}
void Bat::moveLeft()
{
    m_MovingLeft = true;
}
void Bat::moveRight()
{
    m_MovingRight = true;
}
void Bat::stopLeft()
{
    m_MovingLeft = false;
}
void Bat::stopRight()
{
    m_MovingRight = false;
}
void Bat::update(sf::Time dt)
{
    if (m_MovingLeft)
    {
        if (m_Position.x > 0)
            m_Position.x -= m_speed * dt.asSeconds();
    }
    if (m_MovingRight)
    {
        if (m_Position.x < 910)
            m_Position.x += m_speed * dt.asSeconds();
    }
    m_Shape.setPosition(m_Position);
}
