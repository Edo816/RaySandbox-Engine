#ifndef CORE_H
#define CORE_H
#include <iostream>
#include <cmath>
#include <vector>
#include <raylib.h>
#include <raymath.h>
#include "vectorClass.h"
#include <limits>
#define MAX_OBJECTS 200
#define PI 3.1415926535
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
  std::vector<std::vector<int>> map2d;
  int mapRows;
  int mapColumns;
  int map2dX;
  int map2dY;
  Vector2 playerPos;
  Vector2 convertPlayerPos;
  /*double playerAngle;
  double playerDeltaX;
  double playerDeltaY;*/
  Vector2 playerDirection;
  Vector2 convertPlayerDirection;
  double directionLength;
  Vector2 planeVector;
  Vector2 convertPlaneVector;
  double y;
  double fov;
  int draw3Dmap;
  double cameraX; //x-coordinate in camera space
  double rayDirX;
  double rayDirY;
  int mapX;
  int mapY;



  //length of ray from current position to next x or y-side
  double sideDistX;
  double sideDistY;
  double deltaDistX;
  double deltaDistY;
   //length of ray from one x or y-side to next x or y-side

  double perpWallDist;

  //what direction to step in x or y-direction (either +1 or -1)
  int stepX;
  int stepY;

  int hit; //was there a wall hit?
  int side; //was a NS or a EW wall hit?
  int lineHeight;

  //calculate lowest and highest pixel to fill in current stripe
  int drawStart;

  int drawEnd;
  Color color;
  float what;
  int isMovingBlocks;

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
  void DrawMap3D();
  void UpdateMap3D();
  void DrawUIControls();

  float fadeGrid;

};

#endif
