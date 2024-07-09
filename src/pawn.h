#ifndef PAWN_H
#define PAWN_H

#include <raylib.h>

class Pawn{
    private:
        Rectangle pwn;
    public:
        Pawn(Rectangle pwn);
        void Draw();
        void DrawSecond();
        //TO-DO delete after testing
        void Cheet();
};


#endif