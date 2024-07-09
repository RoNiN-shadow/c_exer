#include <raylib.h>
#include "player.h"
#include "pawn.h"
#include "spawner.h"



// Rectangle recc = {500, 10, 51,136};
// Pawn pawn(recc);
Spawner spawner;
int main(){
    InitWindow(800,450, "raylib");
    SetTargetFPS(60);
    
    Rectangle rec = {100, 100, 51, 50};
        
    Player player(rec,20,0);


    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(RAYWHITE);
        float delta = GetFrameTime();
        
        
        
        if (IsKeyPressed(KEY_SPACE)){
            player.Jump();
        }
        
        player.Update(delta);
        
        
        spawner.Update();
        
        spawner.MovePawns();
        spawner.Render();


        player.Draw();
        
        EndDrawing();
        
    }
    CloseWindow();
    return 0;
}