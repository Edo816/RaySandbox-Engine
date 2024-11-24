#include "core.h"




int main(){

  SetConfigFlags(FLAG_WINDOW_RESIZABLE);
  CoreClass core;
  InitWindow(core.windowWidth, core.windowHeight, "Raycaster-Engine");

  SetTargetFPS(60);
  core.buffer = {.data = core.pixelBuffer };
  core.createImageBuffer(&core.buffer);
  core.Update();



  CloseWindow();



  return 0;

}
