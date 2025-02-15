#pragma once

#include "grid.h"
#include "blockVariants.cpp"

class Game{
    public:
        bool gameOver;
        int score;
        
        Game();
        void Draw();
        void HandleInput();
        void MoveBlockDown();
    
    private:    
        void MoveBlockLeft();
        void MoveBlockRight();
        bool IsBlockOutside();
        bool BlokFits();
        void RotateBlock();
        void LockBlock();
        void Reset();
        void UpdateScore(int LinesCleared, int moveDownPoints);
    
        Grid grid;
        vector<Block> GetAllBlocks();
        vector<Block> blocks;
        Block GetRandomBlock();
        Block curBlock;
        Block nextBlock;
};