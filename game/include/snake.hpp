#include <raylib.h>

class Snake{
    public:
        Snake(int cellCount, int cellSize, Color snakeColor);
        void update();
        void draw();
        void setDirection(int direction);
    
    private:
        Color snakeColor;
        Vector2 snakePos;
        int direction;
        int cellCount;
        int cellSize;
};