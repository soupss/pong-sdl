#ifndef BALL_HPP
#define BALL_HPP
#include "sprite.hpp"

class Ball : public Sprite
{
    public:
        inline const static int WIDTH = 50;
        inline const static int HEIGHT = 50;
        Ball();
        Ball(float _x, float _maxY);
        ~Ball() override;
        void move() override;
        void back();
        inline void setY(float _y) {pos.y = _y;}
        void reset(int _x, int _maxY);
        void up();
        void down();
        void left();
        void right();
    private:
        void increaseSpeed();
        const float baseSpeed = 2.5f;
        float speed = baseSpeed;
        int bounces = 0;
};
#endif
