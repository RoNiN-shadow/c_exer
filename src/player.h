#ifndef PLAYER_H
#define PLAYER_H

#include <raylib.h>

class Player{
    private:
        Rectangle pl;
        int balls;
        float speedY;
        float acceleration = 900.0f;
        float jumpVelocity = -300.0f;
    public:
        Player(Rectangle pl, int balls, float speedY);
        Rectangle ShowRec();
        void GravityOnPlayer();
        void Draw();
        void Jump();
        void Update(float delta);
};

#endif