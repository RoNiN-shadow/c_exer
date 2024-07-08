#include "player.h"
#include <raylib.h>

Player::Player(Rectangle pl, int balls){
    this->pl = pl;
    this->balls = balls;
}
Rectangle Player::ShowRec(){
    return pl;
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


void Player::Draw(){
    DrawRectangle(pl.x, pl.y, pl.width, pl.height, BLACK);
}