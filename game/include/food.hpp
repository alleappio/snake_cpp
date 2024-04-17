#include <raylib.h>
#include <cstdlib>
#include <iostream>

class Food{
    public:
        Food(int cellCount, int cellSize, Color foodColor);
        void update();
        Vector2 getPosition();
        void draw();
    
    private:
        Color foodColor;
        Vector2 foodPos;
        int cellCount;
        int cellSize;
};