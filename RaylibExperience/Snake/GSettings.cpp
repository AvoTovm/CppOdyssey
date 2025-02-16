#include "GSettings.h"

Color bg = {173, 204, 96, 255};
Color SColor = {43, 51, 24, 255};

int cellSize = 30;
int offset = 75;
int cellCount = 25;

double lastUpdateTime = 0;

bool eventTriggered(double interval){
    double curTime = GetTime();
    if(curTime - lastUpdateTime >= interval){
        lastUpdateTime = curTime;
        return true;
    }
    return false;
}

bool elementInDeque(Vector2 element, deque<Vector2> deque){
    for(unsigned int i = 0; i < deque.size(); i++){
        if(Vector2Equals(deque[i], element)) return true;
    }
    return false;
}