#include "raylib.h"
#include "player.h"
#include "ball.h"





int main(){
    InitWindow(800,450, "raylib");
    SetTargetFPS(60);
    
    Rectangle rec = {100, 100, 50, 50};
        
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