#include "snake.hpp"

Snake::Snake(Vector2* snakePos, int cellCount, int cellSize){
    this->snakePos = snakePos;
    this->cellCount = cellCount;
    this->cellSize = cellSize;
    this->direction = true;
}

void Snake::update(){
    if(direction){
        this->snakePos->x+=1;
    }else{
        this->snakePos->x-=1;
    }

    if(snakePos->x == cellCount-1 || snakePos->x==0){
        direction=!direction;
    }
}