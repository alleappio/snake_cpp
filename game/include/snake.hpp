#include <raylib.h>
#include <iostream>
#include <list>

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
        bool checkCollisionWithItSelf();
    
    private:
        Color snakeColor;
        Vector2 headPos;
        Vector2 direction;
        std::list<Vector2> body;
        int cellCount;
        int cellSize;
        int length;
};