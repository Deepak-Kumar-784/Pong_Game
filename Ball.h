#define BALL_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Ball
{
private:
    CircleShape ballShape;
    float speedX, speedY;
    bool isMoving; // Flag to control ball movement

public:
    Ball(float radius, float startX, float startY);

    void update(float dt, const sf::RenderWindow &window);
    void reverseX();
    void reverseY();
    void reset(float startX, float startY);
    void start(); // Function to start ball movement
    void stop();  // function to stop the ball movement
    const sf::CircleShape &getShape() const;
};
