#ifndef PADDLE_HPP
#define PADDLE_HPP
#include "sprite.hpp"

class Paddle : public Sprite
{
    public:
        inline const static int WIDTH = 30;
        inline const static int HEIGHT = 160;
        Paddle() = default;
        Paddle(float _x, float _y);
        ~Paddle() override;
        void move() override;
        inline void up() {dir.y = -1;}
        inline void down() {dir.y = 1;}
        inline void stop() {dir.y = 0;}
    private:
        const float speed = 5.0f;
};
#endif
