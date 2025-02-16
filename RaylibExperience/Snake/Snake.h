#pragma once

#include <deque>
#include <iostream>
#include <raylib.h>
#include <raymath.h>
#include "GSettings.h"

using namespace std;

class Snake{
public:
    deque<Vector2> body = {Vector2{6, 9}, Vector2{5, 9}, Vector2{4, 9}};
    Vector2 direction = {1, 0};
    bool addSegment = false;
    Texture2D texture;

    Snake();
    ~Snake();

    void Draw(int offset);
    void Update();
    void Reset();
};