#include <SFML/Graphics.hpp>
using namespace sf;
class Bat
{
private:
    Vector2f m_Position;
    RectangleShape m_Shape;
    float m_speed = 600.0f;
    bool isBatMove = false;
    bool m_MovingLeft = false;
    bool m_MovingRight = false;

public:
    Bat(float startX, float startY);
    FloatRect getPosition(); // It will return 4 values (x,y,w(width),h(height))
    RectangleShape getShape();

    void moveLeft();
    void moveRight();
    void stopLeft();
    void stopRight();
    void start();
    void stop();
    void update(Time dt);
};