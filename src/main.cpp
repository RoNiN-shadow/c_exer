#include <raylib.h>
#include "player.h"
#include "ball.h"





int main(){
    InitWindow(800,450, "raylib");
    SetTargetFPS(60);
    
    Rectangle rec = {100, 100, 50, 50};
        
    Player player(rec,20);

    Ball ball({200, 200}, 30);

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats", 190, 200, 20, LIGHTGRAY);

        player.MovePlayer();

        
        if (CheckCollisionCircleRec(ball.ShowCenter(),ball.ShowRadius(), player.ShowRec()))
            ball.MoveBall();

        player.Draw();
        ball.Draw();

        
        
        
        
        
        EndDrawing();
        
    }
    CloseWindow();
    return 0;
}