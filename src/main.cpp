#include "core.h"

#define WIDTH 1280
#define HEIGHT 720


int main(){

  CoreClass core;
  InitWindow(WIDTH, HEIGHT, "Raycaster-Engine");

  SetTargetFPS(60);

  core.Update();



  CloseWindow();



  return 0;

}
