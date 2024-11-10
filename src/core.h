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
public:
  int windowWidth;
  int windowHeight;
  int startX;
  int startY;
  Rectangle highlightRec;
  int mouseButtonUp;
  int isSelected;
  int place;
  Vector2 startPlacePosition;
  int startPlace;
private:
  //ui
  Rectangle uiRect;


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
