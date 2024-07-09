#include "spawner.h"
#include "pawn.h"
#include <raylib.h>
#include <deque>
#include <iostream>

void Spawner::Spawn(){
    Pawn pawn({900, 10, 51,136});
    pawns.push_back(pawn);
}
void Spawner::MovePawns(){
    for (Pawn& pawn:pawns){
        pawn.Move();
    }
}

void Spawner::Render(){
    for (Pawn& pawn : pawns){
        pawn.Draw();
        pawn.DrawSecond();
        
        
    }
    DeleteLastPawn();
}
void Spawner::DeleteLastPawn(){
    while (!pawns.empty() && pawns.front().pwn.x <= deadZone){
        pawns.pop_front();
    }
}
void Spawner::Update(){
    if (timer < spawnRate){
        timer += GetFrameTime();
    }else{
        Spawn();
        timer = 0;
    }
}