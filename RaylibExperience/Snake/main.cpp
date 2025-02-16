#include <iostream>
#include "Game.h"
#include "GSettings.h"

using namespace std;

// press F5 or use debug button to start

int main(){
    InitWindow(2 * offset + cellSize * cellCount,2 * offset + cellSize * cellCount, "Snake Game");
    SetTargetFPS(60);

    Game game;
    Texture2D BGTexture;
    Image image = LoadImage("Graphic/Floor.png");
    BGTexture = LoadTextureFromImage(image);
    UnloadImage(image);

    while(WindowShouldClose() == false){
        BeginDrawing();
        if(eventTriggered(0.2)) game.Update();

        if(IsKeyPressed(KEY_W) && game.snake.direction.y != 1){
            game.snake.direction = {0, -1};
            game.running = true;
        }
        if(IsKeyPressed(KEY_S) && game.snake.direction.y != -1){
            game.snake.direction = {0, 1};
            game.running = true;
        }
        if(IsKeyPressed(KEY_A) && game.snake.direction.x != 1){
            game.snake.direction = {-1, 0};
            game.running = true;
        }
        if(IsKeyPressed(KEY_D) && game.snake.direction.x != -1){
            game.snake.direction = {1, 0};
            game.running = true;
        }

        ClearBackground(bg);
        DrawRectangleLinesEx(Rectangle{(float)offset - 5, (float)offset - 5, (float)cellSize * cellCount + 10, (float)cellSize * cellCount + 10}, 5 ,SColor);
        DrawTexture(BGTexture, 0, 0, WHITE);
        DrawText(TextFormat("%i", game.score), offset - 15 + cellSize * cellCount, 20, 40, SColor);
        DrawText("Snake Game", offset - 5, 20, 40, SColor);
        
        game.Draw(offset);

        EndDrawing();
    }
    CloseWindow();
    UnloadTexture(BGTexture);
}