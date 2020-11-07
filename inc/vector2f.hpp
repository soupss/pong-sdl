#include <iostream>

struct Vector2f
{
    Vector2f()
    :x(0.0f), y(0.0f)
    { }

    void print()
    {
        std::cout << x << ", " << y << std::endl;
    }

    float x, y;
};
