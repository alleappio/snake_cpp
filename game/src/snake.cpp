#include "snake.hpp"

Snake::Snake(int cellCount, int cellSize, Color snakeColor){
    this->headPos = {1, 1};
    this->cellCount = cellCount;
    this->cellSize = cellSize;
    this->direction = {0,0};
    this->snakeColor = snakeColor;
    this->length = 1;
    this->body.push_back(headPos);
}

void Snake::update(){
    this->headPos.x += this->direction.x;
    this->headPos.y += this->direction.y;
}

void Snake::draw(){
    /*for(int i=0; i < this->length; i++)
        DrawRectangle(this->body[i].x*cellSize, this->body[i].y-i*cellSize, cellSize, cellSize, this->snakeColor);
    */
    DrawRectangle(this->headPos.x*cellSize, this->headPos.y*cellSize, cellSize, cellSize, this->snakeColor);
}

void Snake::setDirection(int direction){
    switch(direction){
        case 0:
            this->direction = {1,0};
            break;
        case 1:
            this->direction = {-1,0};
            break;
        case 2:
            this->direction = {0,1};
            break;
        case 3:
            this->direction = {0,-1};
            break;    
    }
}

int Snake::getDirection(){
    if(this->direction.x == 1 && this->direction.y == 0){
        return 0;
    }
    if(this->direction.x == -1 && this->direction.y == 0){
        return 1;
    }
    if(this->direction.x == 0 && this->direction.y == 1){
        return 2;
    }
    if(this->direction.x == 0 && this->direction.y == -1){
        return 3;
    }
}

void Snake::checkBorderCollision(){
    if(this->headPos.x == -1){
        this->headPos.x = this->cellCount-1;
    }
    else if(this->headPos.x == this->cellCount){
        this->headPos.x = 0;
    }
    if(this->headPos.y == -1){
        this->headPos.y = this->cellCount-1;
    }
    else if(this->headPos.y == this->cellCount){
        this->headPos.y = 0;
    }
}

bool Snake::checkFoodCollision(Vector2 foodPos){
    if(foodPos.x == this->headPos.x && foodPos.y == this->headPos.y){
        return true;
    }
    return false;
}

void Snake::increment(){
    this->length++;
    Vector2 segment = {this->headPos.x, this->headPos.y};
    this->body.push_back(segment);
    std::cout << this->length << std::endl;
}