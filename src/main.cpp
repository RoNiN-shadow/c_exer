#include "include/raylib.h"


//g++ works so much better on windows
//g++ -o game.exe mainy.cpp -O2 -I./include -L./lib -lraylib -lopengl32 -lgdi32 -lwinmm -static -mwindows



class Player{
    private:
        Rectangle pl;
        int balls;

    public:
        void MovePlayer(){
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
        Player(Rectangle pl, int balls){
            this->pl = pl;
            this->balls = balls;
        }
        Rectangle ShowRec(){
            return pl;
        }
};

class Ball{
    private:
        Vector2 center;
        float radius;

    public:
        void MoveBall(){
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
        Ball(Vector2 center, float radius){
            this->center = center;
            this->radius = radius;
        }
        Vector2 ShowCenter(){
            return center;
        }
        float ShowRadius(){
            return radius;
        }

};





int main(){
    InitWindow(800,450, "raylib");
    SetTargetFPS(60);
    
    Rectangle rec;
    rec.x = 100;
    rec.y = 100;
    rec.width = 50;
    rec.height = 50;
        
    Player *player = new Player(rec,20);

    Ball *ball = new Ball({200,200},30);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats", 190, 200, 20, LIGHTGRAY);

        player->MovePlayer();

        
        if (CheckCollisionCircleRec(ball->ShowCenter(),ball->ShowRadius(), player->ShowRec()))
            ball->MoveBall();

        DrawRectangle(player->ShowRec().x,player->ShowRec().y,player->ShowRec().width,player->ShowRec().height, BLACK);
        DrawCircle(ball->ShowCenter().x,ball->ShowCenter().y, ball->ShowRadius(), RED);

        
        
        
        
        
        EndDrawing();
        
    }
    CloseWindow();
    delete player;
    delete ball;
    return 0;
}