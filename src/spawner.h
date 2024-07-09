#ifndef SPAWNER_H
#define SPAWNER_H
#include <deque>
#include "pawn.h"
class Spawner{
    private:
        std::deque<Pawn> pawns;
        float deadZone = 0;
        float timer = 0;
        float spawnRate = 2;
    public:
        void Spawn();
        void Render();
        void DeleteLastPawn();
        void MovePawns();
        void Update();
};


#endif