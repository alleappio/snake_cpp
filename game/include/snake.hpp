#include <raylib.h>

class Snake{
    public:
        Snake(int cellCount, int cellSize, Color snakeColor);
        void update();
        Vector2 getPosition();
        void draw();
    
    private:
        Color snakeColor;
        Vector2 snakePos;
        bool direction;
        int cellCount;
        int cellSize;
};