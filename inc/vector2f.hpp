#ifndef VECTOR2F_HPP
#define VECTOR2F_HPP

struct Vector2f
{
    Vector2f()
        :x(0.0f), y(0.0f)
    { }

    Vector2f(float _x, float _y)
        :x(_x), y(_y)
    { }

    //TODO:operator overloading to add/sub/multiply two vectors

    float x,y;
};
#endif
