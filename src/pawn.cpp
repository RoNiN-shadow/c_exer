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
    DrawRectangle(pwn.x,(pwn.y + 800), pwn.width, pwn.height,GREEN);
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
    DrawText("WITH: ", 190, 200, 20, LIGHTGRAY);
    DrawText(std::to_string(pwn.width).c_str(), 300, 200, 20, LIGHTGRAY );
    DrawText("Height: ", 190, 500, 20, LIGHTGRAY);
    DrawText(std::to_string(pwn.height).c_str(), 300, 500, 20, LIGHTGRAY);
}