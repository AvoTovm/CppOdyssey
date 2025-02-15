#pragma once

#include <vector>
#include <map>
#include "position.h"
#include "colors.h"

using namespace std;

class Block{
    public:
        Block();
        int id;
        map<int, vector<Position>> cells;
        
        void Draw(int offsetX, int offsetY);
        void Move(int rows, int cols);
        void Rotate(); 
        void UndoRotate(); 

        vector<Position> GetCellPosition();

    private:
        int cellSize;
        int rotationState;
        int rowOffset;
        int colOffset;

        vector<Color> colors;
};