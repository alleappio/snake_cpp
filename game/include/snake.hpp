#include <raylib.h>

class Snake{
    public:
        Snake(Vector2* snakePos, int cellCount, int cellSize);
        void update();

    private:
        Vector2* snakePos;
        bool direction;
        int cellCount;
        int cellSize;

};