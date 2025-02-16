#pragma once

#include <raylib.h>
#include <raymath.h>
#include <deque>
#include "GSettings.h"

using namespace std;

class Food{
    public:
        Vector2 position;
        Texture2D texture;
    
        Food(deque<Vector2> snakeBody);
        ~Food();
    
        void Draw(int offset);
        Vector2 GenerateRandomCell();
        Vector2 GenerateRandomPos(deque<Vector2> snakeBody);
    
    };