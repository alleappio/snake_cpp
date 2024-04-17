#include "snake.hpp"

Snake::Snake(int cellCount, int cellSize, Color snakeColor){
    this->snakePos = {1, 1};
    this->cellCount = cellCount;
    this->cellSize = cellSize;
    this->direction = 5;
    this->snakeColor = snakeColor;
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

void Snake::checkBorderCollision(){
    std::cout << "x:" << this->snakePos.x << " y:" << this->snakePos.y << std::endl;
    std::cout << "direction:" << this->direction << std::endl;
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