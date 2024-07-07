#include "player.h"

Player::Player(Rectangle pl, int balls){
    this->pl = pl;
    this->balls = balls;
}

void Player::MovePlayer(){
    float speed = 200.0;
    if (IsKeyDown(KEY_W))
        pl.y -= speed * GetFrameTime();
    if (IsKeyDown(KEY_A))
        pl.x -= speed * GetFrameTime();
    
    if(IsKeyDown(KEY_S))
        pl.y += speed * GetFrameTime();

    if(IsKeyDown(KEY_D))
        pl.x += speed * GetFrameTime();
}

Rectangle Player::ShowRec(){
    return pl;
}