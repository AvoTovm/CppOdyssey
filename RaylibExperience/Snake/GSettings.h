#pragma once

#include <raylib.h>
#include <raymath.h>
#include <deque>

using namespace std;

extern Color bg;
extern Color SColor;

extern int cellSize;
extern int offset;
extern int cellCount;

extern double lastUpdateTime;

bool eventTriggered(double interval);
bool elementInDeque(Vector2 element, deque<Vector2> deque);