#include "food.hpp"

Food::Food(int cellCount, int cellSize, Color foodColor){
    srand((unsigned) time(NULL));

    this->foodPos = {rand()%cellCount, rand()%cellCount};
    this->cellCount = cellCount;
    this->cellSize = cellSize;
    this->foodColor = foodColor;
}

void Food::update(){
    //TODO
}

void Food::draw(){
    DrawRectangle(this->foodPos.x*cellSize, this->foodPos.y*cellSize, cellSize, cellSize, this->foodColor);
}

Vector2 Food::getPosition(){
    return this->foodPos;
}