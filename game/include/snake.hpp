#include <raylib.h>

class Snake{
    public:
        Snake(int cellCount, int cellSize);
        void update();
        Vector2 getPosition();
        
    private:
        Vector2 snakePos;
        bool direction;
        int cellCount;
        int cellSize;
};