#include "snake.hpp"

Snake::Snake(int cellCount, int cellSize, Color snakeColor){
    this->snakePos = {1, 1};
    this->cellCount = cellCount;
    this->cellSize = cellSize;
    this->direction = true;
    this->snakeColor = snakeColor;
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

void Snake::draw(){
    DrawRectangle(this->snakePos.x*cellSize, this->snakePos.y*cellSize, cellSize, cellSize, this->snakeColor);

}

Vector2 Snake::getPosition(){
    return this->snakePos;
}