#include <raylib.h>
#include "player.h"
#include "pawn.h"



Rectangle recc = {100, 100, 50,50};
Pawn pawn(recc);

int main(){
    InitWindow(800,450, "raylib");
    SetTargetFPS(60);
    
    Rectangle rec = {100, 100, 50, 50};
        
    Player player(rec,20,0);


    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        float delta = GetFrameTime();
        
        if (IsKeyPressed(KEY_SPACE)){
            player.Jump();
        }
        
        player.Update(delta);
        
        pawn.Cheet();
        
        pawn.Draw();
        pawn.DrawSecond();
        player.Draw();
        
        EndDrawing();
        
    }
    CloseWindow();
    return 0;
}