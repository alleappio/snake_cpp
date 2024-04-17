#include <raylib.h>
#include <iostream>

class Snake{
    public:
        Snake(int cellCount, int cellSize, Color snakeColor);
        void update();
        void draw();
        void setDirection(int direction);
        void checkBorderCollision();
    
    private:
        Color snakeColor;
        Vector2 snakePos;
        int direction;
        int cellCount;
        int cellSize;
};