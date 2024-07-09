#ifndef PAWN_H
#define PAWN_H

#include <raylib.h>

class Pawn{
    private:
        
        float moveSpeed = 5;
        float speed;
        float acceleration = -100.0f;
    public:
        Rectangle pwn;
        Pawn(Rectangle pwn);
        void Draw();
        void DrawSecond();
        //TO-DO delete after testing
        void Cheet();
        void Move();
};


#endif