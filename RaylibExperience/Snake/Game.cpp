#include"Game.h"

void Game::Draw(int offset){
    snake.Draw(offset);
    food.Draw(offset);
}

void Game::Update(){
    if(running){
        snake.Update();
        CheckFoodColiision();
        CheckColisionOutOfBounds();
        CheckTailColision();
    }
}

void Game::CheckFoodColiision(){
    if(Vector2Equals(snake.body[0], food.position)){
        food.position = food.GenerateRandomPos(snake.body);
        snake.addSegment = true;
        score++;
    }
}

void Game::CheckColisionOutOfBounds(){
    if(snake.body[0].x == cellCount || snake.body[0].x == -1) GameOver();
    if(snake.body[0].y == cellCount || snake.body[0].y == -1) GameOver();
}

void Game::CheckTailColision(){
    deque<Vector2> headlessBody = snake.body;
    headlessBody.pop_front();
    if(elementInDeque(snake.body[0], headlessBody)) GameOver();
}

void Game::GameOver(){
    snake.Reset();
    food.position = food.GenerateRandomPos(snake.body);
    running = false;
    score = 0;
}