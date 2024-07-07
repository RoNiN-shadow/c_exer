#ifndef BALL_H
#define BALL_H

#include "raylib.h"

class Ball{
    private:
        Vector2 center;
        float radius;
    public:
        Ball(Vector2 center, float radius);
        Vector2 ShowCenter();
        float ShowRadius();
        void MoveBall();
};


#endif