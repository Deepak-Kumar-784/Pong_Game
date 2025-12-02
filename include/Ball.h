#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

class Ball
{
private:
    sf::CircleShape ballShape;
    float speedX, speedY;
    bool isMoving;

public:
    Ball(float radius, float startX, float startY);

    void update(float dt, const sf::RenderWindow &window);
    void reverseX();
    void reverseY();
    void reset(float startX, float startY);
    void start();
    void stop();
    const sf::CircleShape &getShape() const;
};

#endif // BALL_H
