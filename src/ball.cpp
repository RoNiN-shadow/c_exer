#include "src/ball.h"
#include "include/raylib.h"

Ball::Ball(Vector2 center, float radius){
    this->center = center;
    this->radius = radius;
}

Vector2 Ball::ShowCenter(){
    return center;
}

float Ball::ShowRadius(){
    return radius;
}

void Ball::MoveBall(){
    float speed = 200.0;
    
    int dx = 0, dy = 0;

    if (IsKeyDown(KEY_W))
        dy -= speed * GetFrameTime();

    if (IsKeyDown(KEY_A))
        dx -= speed * GetFrameTime();
    
    if(IsKeyDown(KEY_S))
        dy += speed * GetFrameTime();

    if(IsKeyDown(KEY_D))
        dx += speed * GetFrameTime();


    center.x += dx;
    center.y += dy;
}