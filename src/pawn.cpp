#include "pawn.h"
#include <raylib.h>
#include <string>

Pawn::Pawn(Rectangle pwn){
    this->pwn = pwn;
}
void Pawn::Draw(){
    DrawRectangle(pwn.x,pwn.y,pwn.width,pwn.height, GREEN);
}
void Pawn::DrawSecond(){
    DrawRectangle(pwn.x,(pwn.y + 300), pwn.width, pwn.height,GREEN);
}
void Pawn::Cheet(){
    if (IsKeyDown(KEY_I)){
        pwn.width++;
    }
    if (IsKeyDown(KEY_O)){
        pwn.width --;
    }
    if (IsKeyDown(KEY_K)){
        pwn.height ++;
    }
    if (IsKeyDown(KEY_L)){
        pwn.height --;
    }
    
}