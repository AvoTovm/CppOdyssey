#include "Snake.h"

Snake::Snake(){
    Image image = LoadImage("Graphic/Snake02.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
}

Snake::~Snake(){
    UnloadTexture(texture);
}

void Snake::Draw(int offset){
    for(unsigned int i = 0; i < body.size(); i++){
        float x = body[i].x;
        float y = body[i].y;
        DrawTexture(texture, offset + x * cellSize, offset + y * cellSize, WHITE);
    }
}

void Snake::Update(){
    body.push_front(Vector2Add(body[0], direction));
    if(addSegment == true){
        addSegment = false;
    }else body.pop_back();
}

void Snake::Reset(){
    body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    direction = {1, 0};
}