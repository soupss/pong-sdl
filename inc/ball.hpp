#ifndef BALL_HPP
#define BALL_HPP
#include "sprite.hpp"

class Ball : public Sprite
{
    public:
        inline const static int WIDTH = 20;
        inline const static int HEIGHT = 20;
        Ball();
        Ball(float _x, float _y);
        ~Ball() override;
        void move() override;
        void back();
        inline void setY(float _y) {pos.y = _y;}
        void reset(int _x, int _y);
        void up();
        void down();
        void left();
        void right();
    private:
        void increaseSpeed();
        const float baseSpeed = 3.5f;
        float speed = baseSpeed;
        int bounces = 0;
};
#endif
