#include "snake.hpp"

Snake::Snake(int cellCount, int cellSize){
    this->snakePos = {1, 1};
    this->cellCount = cellCount;
    this->cellSize = cellSize;
    this->direction = true;
}

void Snake::update(){
    if(direction){
        this->snakePos.x+=1;
    }else{
        this->snakePos.x-=1;
    }

    if(this->snakePos.x == cellCount-1 || this->snakePos.x==0){
        direction=!direction;
    }
}

Vector2 Snake::getPosition(){
    return this->snakePos;
}