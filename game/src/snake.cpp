#include "snake.hpp"

Snake::Snake(int cellCount, int cellSize, Color snakeColor){
    this->snakePos = {1, 1};
    this->cellCount = cellCount;
    this->cellSize = cellSize;
    this->direction = 5;
    this->snakeColor = snakeColor;
    this->length = 1;
}

void Snake::update(){
    switch(direction){
        case 0:
            this->snakePos.x+=1;
            break;
        case 1:
            this->snakePos.x-=1;
            break;
        case 2:
            this->snakePos.y+=1;
            break;
        case 3:
            this->snakePos.y-=1;
            break;    
    }
}

void Snake::draw(){
    DrawRectangle(this->snakePos.x*cellSize, this->snakePos.y*cellSize, cellSize, cellSize, this->snakeColor);
}

void Snake::setDirection(int direction){
    this->direction=direction;
}

int Snake::getDirection(){
    return this->direction;
}

void Snake::checkBorderCollision(){
    if(this->snakePos.x == -1){
        this->snakePos.x = this->cellCount-1;
        //this->direction=5;
    }
    else if(this->snakePos.x == this->cellCount){
        this->snakePos.x = 0;
        //this->direction=5;
    }
    if(this->snakePos.y == -1){
        this->snakePos.y = this->cellCount-1;
        //this->direction=5;
    }
    else if(this->snakePos.y == this->cellCount){
        this->snakePos.y = 0;
        //this->direction=5;
    }
}

bool Snake::checkFoodCollision(Vector2 foodPos){
    if(foodPos.x == this->snakePos.x && foodPos.y == this->snakePos.y){
        return true;
    }
    return false;
}

void Snake::increment(){
    this->length++;
    std::cout << this->length << std::endl;
}