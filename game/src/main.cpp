#include <iostream>
#include <raylib.h>

#include "snake.hpp"
#include "food.hpp"

const int WINDOW_WIDTH = 750;
const int WINDOW_HEIGHT = 750;

const int CELLSIZE = 25;
const int CELLCOUNT = 25;

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};
Color red = {100, 11, 11, 255};

int main () {
  std::cout << "INFO: starting..." << std::endl;

  InitWindow(CELLSIZE*CELLCOUNT ,CELLSIZE*CELLCOUNT, "Snake");
  SetTargetFPS(60);
  
  int count = 0;
  bool run = true;
  Snake* snake = new Snake(CELLCOUNT, CELLSIZE, darkGreen);
  Food* food = new Food(CELLCOUNT, CELLSIZE, red);
  
  while(WindowShouldClose() == false){
    BeginDrawing();

    if(run){
      DrawText(TextFormat("SCORE: %i", snake->getLength()), CELLSIZE*CELLCOUNT-100, CELLSIZE, 20, darkGreen);

      snake->draw();
      food->draw();

      int direction = snake->getDirection();
      if (IsKeyDown(KEY_RIGHT) && direction!=1) snake->setDirection(0);
      if (IsKeyDown(KEY_LEFT) && direction!=0) snake->setDirection(1);
      if (IsKeyDown(KEY_DOWN) && direction!=3) snake->setDirection(2);
      if (IsKeyDown(KEY_UP) && direction!=2) snake->setDirection(3);


      if(count%10==0){
        snake->update();
      }

      count++;

      snake->checkBorderCollision();
      if(snake->checkFoodCollision(food->getPosition())){
        food->update();
        snake->increment();
      }
      if(snake->getLength()>2){
        if(snake->checkCollisionWithItSelf()){
          run=false;
        }
      }
    }
    else{
      DrawText(TextFormat("GAME OVER"), CELLSIZE*CELLCOUNT/2-150, CELLSIZE*CELLCOUNT/2-50, 50, red);
    }
    ClearBackground(green);
    EndDrawing();
  }
  CloseWindow();
  return 0;
}