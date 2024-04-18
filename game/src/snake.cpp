#include "snake.hpp"

Snake::Snake(int cellCount, int cellSize, Color snakeColor){
    this->headPos = {1, 1};
    this->cellCount = cellCount;
    this->cellSize = cellSize;
    this->direction = {0,0};
    this->snakeColor = snakeColor;
    this->length = 1;
    this->body.push_front(headPos);
}

void Snake::update(){
    Vector2 segment = this->body.front();
    segment.x += this->direction.x;
    segment.y += this->direction.y;
    this->body.pop_back();
    this->body.push_front(segment);
}

void Snake::draw(){
    //DrawRectangle(this->body.front().x*cellSize, this->body.front().y*cellSize, cellSize, cellSize, this->snakeColor);
    /*for (std::list<Vector2>::const_iterator i = this->body.begin(); i != this->body.end(); ++i){
        DrawRectangle(i->x*cellSize, i->y*cellSize, cellSize, cellSize, this->snakeColor);
    }*/
    for(auto const i : body){
        DrawRectangle(i.x*cellSize, i.y*cellSize, cellSize, cellSize, this->snakeColor);
    }
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
    if(this->body.front().x == -1){
        this->body.front().x = this->cellCount-1;
    }
    else if(this->body.front().x == this->cellCount){
        this->body.front().x = 0;
    }
    if(this->body.front().y == -1){
        this->body.front().y = this->cellCount-1;
    }
    else if(this->body.front().y == this->cellCount){
        this->body.front().y = 0;
    }
}

bool Snake::checkFoodCollision(Vector2 foodPos){
    if(foodPos.x == this->body.front().x && foodPos.y == this->body.front().y){
        return true;
    }
    return false;
}

bool Snake::checkCollisionWithItSelf(){

}

void Snake::increment(){
    this->length++;
    Vector2 segment = {this->body.front().x, this->body.front().y};
    this->body.push_front(segment);
    std::cout << this->length << std::endl;
}
