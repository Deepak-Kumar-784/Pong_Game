#include "Bat.h"
Bat::Bat(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;
    m_Shape.setSize(sf::Vector2f(50, 5));
    m_Shape.setFillColor(sf::Color::White);
    m_Shape.setPosition(m_Position);
}
FloatRect Bat::getPosition()
{
    return m_Shape.getGlobalBounds(); // In-built function in SFML library in order to get 4 values
}
RectangleShape Bat::getShape()
{
    return m_Shape;
}
void Bat::start()
{
    isBatMove = true;
}
void Bat::stop(){
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
    m_MovingLeft = false; // Stop the extreme left side
}
void Bat::stopRight()
{
    m_MovingRight = false; // Stop the extreme right side
}
void Bat::update(Time dt)
{
    if (m_MovingLeft)
    {
        if (m_Position.x > 0)
            m_Position.x -= m_speed * dt.asSeconds();
    }
    if (m_MovingRight)
    {
        // 920 value is for left upper corner then my right upper corner value will be 960
        if (m_Position.x < 910) // As i set the height of the bat 40 so 960-20 = 940
            m_Position.x += m_speed * dt.asSeconds();
    }
    m_Shape.setPosition(m_Position);
}
// m_Shape.setPosition(m_Position);