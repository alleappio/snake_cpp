#include <iostream>
#include <raylib.h>
#include "snake.hpp"

const int WINDOW_WIDTH = 750;
const int WINDOW_HEIGHT = 750;

const int CELLSIZE = 25;
const int CELLCOUNT = 25;

Color green = {173, 204, 96, 255};
Color darkGreen = {43, 51, 24, 255};

int main () {
  std::cout << "INFO: starting..." << std::endl;

  InitWindow(CELLSIZE*CELLCOUNT ,CELLSIZE*CELLCOUNT, "Snake");
  SetTargetFPS(60);
  
  int count = 0;

  Snake* snake = new Snake(CELLCOUNT, CELLSIZE);

  while(WindowShouldClose() == false){
    BeginDrawing();

    DrawRectangle(snake->getPosition().x*CELLSIZE, snake->getPosition().y*CELLSIZE, CELLSIZE, CELLSIZE, darkGreen);
    
    if(count%15==0){
      snake->update();
    }

    count++;

    ClearBackground(green);

    EndDrawing();
  }

  CloseWindow();
  return 0;
}