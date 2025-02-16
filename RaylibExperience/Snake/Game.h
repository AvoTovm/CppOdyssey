#pragma once

#include <raylib.h>
#include <raymath.h>
#include "Food.h"
#include "Snake.h"

using namespace std;

class Game{
    public:
        Snake snake;
        Food food = Food(snake.body);
        
        bool running = true;
        int score = 0;
    
        void Draw(int offset);
        void Update();
        void CheckFoodColiision();
        void CheckColisionOutOfBounds();
        void CheckTailColision();
        void GameOver();
    };