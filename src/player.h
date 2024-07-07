#ifndef PLAYER_H
#define PLAYER_H

#include "raylib.h"

class Player{
    private:
        Rectangle pl;
        int balls;
    public:
        Player(Rectangle pl, int balls);

        void MovePlayer();
        Rectangle ShowRec();
};






#endif