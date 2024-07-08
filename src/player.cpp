#include "player.h"
#include <raylib.h>

Player::Player(Rectangle pl, int balls, float speedY){
    this->pl = pl;
    this->balls = balls;
    this->speedY = speedY;
}
Rectangle Player::ShowRec(){
    return pl;
}



void Player::Draw(){
    DrawRectangle(pl.x, pl.y, pl.width, pl.height, BLACK);
}
void Player::Jump(){
    speedY = jumpVelocity;
}
void Player::Update(float delta){
    const float gravity = 900.0f;
    const float jumpForce = -300.0f;

    speedY += acceleration * delta;
    pl.y += speedY * delta;
}