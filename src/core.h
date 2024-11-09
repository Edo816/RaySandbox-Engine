#ifndef CORE_H
#define CORE_H
#include <iostream>
#include <cmath>
#include <vector>
#include <raylib.h>
#include "vectorClass.h"
#define MAX_OBJECTS 200
class CoreClass
{
private:
  //ui
  Rectangle uiRect = {1000,0,280,720};


  //player
  double posX , posY;  //x and y start position
  double dirX, dirY; //initial direction vector
  double planeX , planeY; //the 2d raycaster version of camera plane

public:

  CoreClass();

  ~CoreClass();


  VectorClass vectors;
  int objectCounter;
  void addObject();
  void Update();
  void DrawingManager();
    void DrawMap2D();
    void UpdateMap2D();
    void DrawUIControls();
      float fadeGrid;

};

#endif
