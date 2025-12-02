#ifndef BAT_H
#define BAT_H

#include <SFML/Graphics.hpp>

class Bat
{
private:
    sf::Vector2f m_Position;
    sf::RectangleShape m_Shape;
    float m_speed = 600.0f;
    bool isBatMove = false;
    bool m_MovingLeft = false;
    bool m_MovingRight = false;

public:
    Bat(float startX, float startY);
    sf::FloatRect getPosition();
    sf::RectangleShape getShape();

    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    void start();
    void stop();
    void update(sf::Time dt);
};

#endif // BAT_H
