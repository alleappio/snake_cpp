#include <raylib.h>
#include <iostream>

class Snake{
    public:
        Snake(int cellCount, int cellSize, Color snakeColor);
        void update();
        void draw();
        void setDirection(int direction);
        int getDirection();
        void checkBorderCollision();
        bool checkFoodCollision(Vector2 foodPos);
        void increment();
    
    private:
        Color snakeColor;
        Vector2 snakePos;
        int direction;
        int cellCount;
        int cellSize;
        int length;
};