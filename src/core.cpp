#include "core.h"

CoreClass::CoreClass(){
  vectors.rectangleSelected = 0;

  this->windowWidth = 1280;
  this->windowHeight = 720;
  this->startX = 0;
  this->startY = 0;
  this->highlightRec = {0,0, 25,25};
  this->isSelected=0;
  this->place=0;
  this->startPlace=0;
  this->startPlacePosition = {0,0};
  this->mapRows = 40;
  this->mapColumns = 40;
  this->playerPos = {-16,16};
  this->convertPlayerPos = vectors.ConvertRaylibScreenCoordinates(this->playerPos,this->startX,this->startY);
  this->directionLength = 1;
  this->playerDirection = {1,0};
//  this->convertPlayerDirection = vectors.ConvertRaylibScreenCoordinates({(playerPos.x+(playerDirection.x)),playerPos.y+(playerDirection.y)},this->startX,this->startY);
  this->convertPlayerDirection = vectors.ConvertRaylibScreenCoordinates({this->playerPos.x+this->playerDirection.x,this->playerPos.y+this->playerDirection.y},this->startX,this->startY);
  this->planeVector = {0,0.77};
  std::cout << "planeX: " << planeVector.x << '\n';
  std::cout << "planeY: " << planeVector.y << '\n';
  this->convertPlaneVector = vectors.ConvertRaylibScreenCoordinates(this->planeVector,0,this->startY);

  this->draw3Dmap = 0;


/*  this->playerDeltaX = cos(playerAngle)*5;
  this->playerDeltaY = sin(playerAngle)*5;*/
  std::vector<std::vector<int>>  map( mapRows , std::vector<int> (mapColumns, 0));
  map2d = map;





  VectorClass::Objects objects[MAX_OBJECTS] = {
    {{-10,-2}, {25,25},RED,0},{{-4, -2}, {25,25},RED,0}   };
  for (int i = 0; i < 2; i++) {
    vectors.object.push_back(objects[i]);
  }


    for (int x = -20; x <= 19; x++) {
        VectorClass::Objects new_object = {{x,20},{25,25},RED,0};
            vectors.object.push_back(new_object);
    }

    for (int x = -20; x <= 19; x++) {
        VectorClass::Objects new_object = {{x,-19},{25,25},RED,0};
            vectors.object.push_back(new_object);
    }

    for (int y = 19; y >= -18; y--) {
        VectorClass::Objects new_object = {{-20,y},{25,25},RED,0};
            vectors.object.push_back(new_object);
    }

    for (int y = 19; y >= -18; y--) {
        VectorClass::Objects new_object = {{19,y},{25,25},RED,0};
            vectors.object.push_back(new_object);
    }

  objectCounter = vectors.object.size();


  fadeGrid = 0.2f;


  posX = 22, posY = 12;  //x and y start position
  dirX = -1, dirY = 0; //initial direction vector
  planeX = 0, planeY = 0.66; //the 2d raycaster version of camera plane
  /*  int worldMap[24][24]=
  { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}};
}*/
}


void CoreClass::DrawMap3D(){
  //which box of the map we're in

  for(int x = 0; x < GetScreenWidth(); x++)
  {
    //calculate ray position and direction

     cameraX = 2 * x / double(GetScreenWidth()) - 1; //x-coordinate in camera space
     rayDirX = (playerDirection.x+(-(planeVector.x*cameraX)));
     rayDirY = (playerDirection.y+(-(planeVector.y*cameraX)));
     mapX = ((int)(playerPos.x));
     mapY = ((int)(playerPos.y));
     //DrawLineV(convertPlayerPos,vectors.ConvertRaylibScreenCoordinates({(playerPos.x+playerDirection.x+((planeVector.x*cameraX))),(playerPos.y+playerDirection.y+((planeVector.y*cameraX)))},startX,startY),BLUE);
  /*   if (-(i-20) == a.position.y && (j-20) == a.position.x) {
       map2d[-((int)a.position.y-20)][(int)a.position.x+20] = 1;
     }*/
     //std::cout << "playerX: " << (int)playerPos.x<< '\n';
     //std::cout << "playerY: " << (int)playerPos.y<< '\n';

    //length of ray from current position to next x or y-side

     deltaDistX = (rayDirX == 0) ? 1e30 : std::abs(1 / rayDirX);
     deltaDistY = (rayDirY == 0) ? 1e30 : std::abs(1 / rayDirY);

     //length of ray from one x or y-side to next x or y-side



    //what direction to step in x or y-direction (either +1 or -1)

     hit = 0; //was there a wall hit?



  if (rayDirX < 0)
  {
    stepX = -1;
    sideDistX = (playerPos.x - mapX) * deltaDistX;
  }
  else
  {
    stepX = 1;
    sideDistX = (mapX + 1.0 - playerPos.x) * deltaDistX;
  }
  if (rayDirY < 0)
  {
    stepY = -1;
    sideDistY = (playerPos.y - mapY) * deltaDistY;
  }
  else
  {
    stepY = 1;
    sideDistY = (mapY + 1.0 - playerPos.y) * deltaDistY;
  }
  // std::cout << "map: " << map2d[(20-(mapY))-1][(20+(mapX))-1] << '\n';
  // std::cout << "mapX: " << mapX << '\n';
  // std::cout << "mapY: " << mapY << '\n';
  //perform DDA
//DrawLineV(convertPlayerPos,vectors.ConvertRaylibScreenCoordinates({(playerPos.x+playerDirection.x+(planeVector.x*cameraX)),playerPos.y+playerDirection.y+(planeVector.y*cameraX)},startX,startY),BLUE);
//DrawLineV(convertPlayerPos,vectors.ConvertRaylibScreenCoordinates({(playerPos.x+playerDirection.x+(planeVector.x*cameraX)+sideDistX),playerPos.y+playerDirection.y+(planeVector.y*cameraX)+sideDistY},startX,startY),GREEN);
  while (hit == 0  )
  {


    //jump to next map square, either in x-direction, or in y-direction

    if (sideDistX < sideDistY )
    {
      sideDistX += deltaDistX;
    //  if(mapX <= 40 && mapX >= 0){
        mapX = mapX + (stepX);
      //}

      side = 0;
    }
    else if( sideDistX >= sideDistY )
    {
      sideDistY += deltaDistY;
  //    if(mapY <= 40 && mapY >= 0){
        mapY = mapY + (stepY);
    //  }
      side = 1;
    }

      //Check if ray has hit a wall
    if (map2d[(20-(mapY))-1][(20+(mapX))-1] > 0) hit = 1;
    // std::cout << "playerX: " << playerPos.x << '\n';
    // std::cout << "playerY: " << playerPos.y<< '\n';
    // std::cout << "map: " << map2d[mapY][mapX] << '\n';
    // std::cout << "map: " << map2d[mapY][mapX] << '\n';
  }

      if(side == 0) {perpWallDist = (sideDistX - deltaDistX);}
      else {         perpWallDist = (sideDistY - deltaDistY);}
      //Calculate height of line to draw on screen
       lineHeight = (int)(GetScreenHeight() / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
       drawStart = -lineHeight / 2 + GetScreenHeight() / 2;
      if(drawStart < 0)drawStart = 0;
       drawEnd = lineHeight / 2 + GetScreenHeight() / 2;
      if(drawEnd >= GetScreenHeight())drawEnd = GetScreenHeight() - 1;
       color;
      switch(map2d[(20-(mapY))-1][(20+(mapX))-1])
      {
        case 1:  color = RED;  break; //red
        case 2:  color = BLUE;  break; //green
        default: color = RED; break; //yellow
      }

      //give x and y sides different brightness
      if (side == 1) {color =  {color.r/2,color.g/2,color.b/2,color.a};}

      //draw the pixels of the stripe as a vertical line
      //DrawLineV(x, drawStart, drawEnd, color);
      DrawLineEx({x,drawStart}, {x,drawEnd}, 1, color);







  }

}

void CoreClass::UpdateMap3D(){

}









void CoreClass::addObject(){
  int key = GetKeyPressed();
  highlightRec.x = (int)vectors.ConvertMousePosition.x;
  highlightRec.y = (int)vectors.ConvertMousePosition.y+1;
  Vector2 rec;
  DrawRectangleV( vectors.ConvertRaylibScreenCoordinates({highlightRec.x, highlightRec.y},startX,startY),{highlightRec.width,highlightRec.height},YELLOW);

  for (auto& a : vectors.object) {
    if((int)vectors.ConvertMousePosition.x==a.position.x&&(int)vectors.ConvertMousePosition.y+1==a.position.y){
      place = 1;
    }
  }

  if (key == 32 && place == 0 && (highlightRec.x >= (-20) && highlightRec.x <= (19)) && (highlightRec.y <= (20) && highlightRec.y >= (-19))  )  {

    VectorClass::Objects new_object = {{(int)vectors.ConvertMousePosition.x,(int)vectors.ConvertMousePosition.y+1},{25,25},RED,0};
    vectors.object.push_back(new_object);
    place = 1;

  }

  place = 0;


}

void CoreClass::UpdateMap2D(){


  vectors.ConvertMousePosition = {vectors.ConvertRaylibMouseCoordinateX((float)GetMouseX(),startX),vectors.ConvertRaylibMouseCoordinateY((float)GetMouseY(),startY)};
  Vector2 convertRectangle;
  //playerDirection = {0,1*directionLength};
  //planeVector = {(playerPos.x+playerDirection.x)/2,((playerPos.y+playerDirection.y))};

  convertPlayerPos = vectors.ConvertRaylibScreenCoordinates(playerPos,startX,startY);
  convertPlayerDirection = vectors.ConvertRaylibScreenCoordinates({playerPos.x+playerDirection.x,playerPos.y+playerDirection.y},startX,startY);
  //std::cout << "convertPlayerDirection: " << convertPlayerDirection.x << '\n';
  convertPlaneVector = vectors.ConvertRaylibScreenCoordinates({playerPos.x+playerDirection.x+planeVector.x,playerPos.y+playerDirection.y+planeVector.y},startX,startY);
  Vector2 convertPlaneVector2 = vectors.ConvertRaylibScreenCoordinates({playerPos.x+playerDirection.x-planeVector.x,playerPos.y+playerDirection.y-planeVector.y},startX,startY);
  Vector2 convertPlaneVectorExtend = vectors.ConvertRaylibScreenCoordinates({playerPos.x+playerDirection.x-planeVector.x,playerPos.y+playerDirection.y-planeVector.y},startX,startY);
  double plane1Slope = (playerPos.y+playerDirection.y+planeVector.y) - playerPos.y / (playerPos.x+playerDirection.x+planeVector.x) - playerPos.x;
//  double b = playerPos.y - (plane1Slope * playerPos.x);





  DrawLineV(convertPlayerPos,convertPlayerDirection,BLUE);
  DrawLineV(convertPlayerDirection,convertPlaneVector,YELLOW);
  DrawLineV(convertPlayerDirection,convertPlaneVector2,YELLOW);
  DrawLineV(convertPlayerPos,convertPlaneVector,YELLOW);
  DrawLineV(convertPlayerPos,convertPlaneVector2,YELLOW);
  DrawLineV(convertPlayerPos,vectors.ConvertRaylibScreenCoordinates({(playerPos.x+(playerDirection.x*(20))+(planeVector.x*20)),playerPos.y+(playerDirection.y*(20))+(planeVector.y*20)},startX,startY),YELLOW);
  DrawLineV(convertPlayerPos,vectors.ConvertRaylibScreenCoordinates({(playerPos.x+(playerDirection.x*(20))-(planeVector.x*20)),playerPos.y+(playerDirection.y*(20))-(planeVector.y*20)},startX,startY),YELLOW);

    Vector2 posDirPlane1 = {playerPos.x+playerDirection.x-(planeVector.x), playerPos.y+playerDirection.y-(planeVector.y)};
    Vector2 posDirPlane2 = {playerPos.x+playerDirection.x+(planeVector.x), playerPos.y+playerDirection.y+(planeVector.y)};
    Vector2 ray1 = {(playerPos.x+playerDirection.x-(planeVector.x)), (planeVector.y)};
    Vector2 ray2 = {(playerPos.x+playerDirection.x+(planeVector.x)), (planeVector.y)};
  //DrawLineV({((convertPlayerDirection.x)-convertPlaneVector.x),convertPlayerDirection.y},{((convertPlayerDirection.x)+convertPlaneVector.x),convertPlayerDirection.y},YELLOW);
  /*  DrawLineV(convertPlayerDirection,vectors.ConvertRaylibScreenCoordinates(posDirPlane1,startX,startY),YELLOW);
    DrawLineV(convertPlayerDirection,vectors.ConvertRaylibScreenCoordinates(posDirPlane2,startX,startY),BLUE);
    DrawLineV(convertPlayerPos,vectors.ConvertRaylibScreenCoordinates(ray2,startX,startY),YELLOW);
    DrawLineV(convertPlayerPos,vectors.ConvertRaylibScreenCoordinates(ray1,startX,startY),YELLOW);*/
    //std::cout << "convertDirection: " <<vectors.ConvertRaylibScreenCoordinates(posDirPlane2,startX,startY).x  << '\n';
//  DrawLineV(convertPlaneVector,{convertPlaneVector.x+((convertPlayerDirection.x-convertPlaneVector.x)*2),convertPlaneVector.y},YELLOW);
  //DrawLineV(convertPlaneVector,{convertPlaneVector.x*2,convertPlaneVector.y},YELLOW);
  for (auto& a : vectors.object) {




    /*  if(IsMouseButtonUp(MOUSE_BUTTON_LEFT)){

    for (auto& a : vectors.object) {

    a.selected = 0;

  }
}*/
if(a.selected == 1&&(!IsMouseButtonDown(MOUSE_BUTTON_LEFT))){
  DrawLineV(vectors.ConvertRaylibScreenCoordinates(a.position,startX,startY),vectors.ConvertRaylibScreenCoordinates({(int)vectors.ConvertMousePosition.x,(int)vectors.ConvertMousePosition.y},startX,startY), YELLOW);
  DrawText("blocks moved",320,120,20,WHITE);
  for (auto& a : vectors.object) {
    if((int)vectors.ConvertMousePosition.x==a.position.x&&(int)vectors.ConvertMousePosition.y+1==a.position.y){
      place = 1;
    }
  }
  if(place == 0){
    if ((highlightRec.x >= (-20) && highlightRec.x <= (19)) && (highlightRec.y <= (20) && highlightRec.y >= (-19))) {
      a.position.x = (int)vectors.ConvertMousePosition.x;
      a.position.y = (int)vectors.ConvertMousePosition.y+1;
    }else{
      place = 1;
    }

  }
  if(place == 1){
    a.position.x = (int)startPlacePosition.x;
    a.position.y = (int)startPlacePosition.y;
  }
  for (auto& a : vectors.object) {

    a.selected = 0;
    isSelected = 0;
    place = 0;
    startPlace = 0;

  }

}
if(a.selected == 1){
  DrawLineV(vectors.ConvertRaylibScreenCoordinates(a.position,startX,startY),vectors.ConvertRaylibScreenCoordinates({(int)vectors.ConvertMousePosition.x,(int)vectors.ConvertMousePosition.y},startX,startY), YELLOW);

}

if(((vectors.ConvertMousePosition.x >=  a.position.x && vectors.ConvertMousePosition.x <= (a.position.x+1))&&(vectors.ConvertMousePosition.y >=  a.position.y-1 && vectors.ConvertMousePosition.y <= (a.position.y)))){
  a.color = YELLOW;
  DrawLineV(vectors.ConvertRaylibScreenCoordinates(a.position,startX,startY),vectors.ConvertRaylibScreenCoordinates({(int)vectors.ConvertMousePosition.x,(int)vectors.ConvertMousePosition.y},startX,startY), YELLOW);
  DrawText("selecting blocks",320,40,20,WHITE);
  //std::cout << "isSelected: " << isSelected << '\n';
  if(   IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
    if(startPlace == 0){
      startPlacePosition.x = a.position.x;
      startPlacePosition.y = a.position.y;
      startPlace = 1;
    }
    if(isSelected == 0){
      for (auto& a : vectors.object) {
        if(a.selected == 1){
          isSelected = 1;
        }


      }

    }

    if(isSelected == 0){
      a.selected = 1;
    }

    vectors.rectangleSelected = 1;
    if (a.selected == 1) {
      DrawText("moving blocks",320,80,20,WHITE);
      a.position.x = vectors.ConvertMousePosition.x-0.5;
      a.position.y = vectors.ConvertMousePosition.y+0.5;
    }


  }
  if(a.selected == 1&&(!IsMouseButtonDown(MOUSE_BUTTON_LEFT))){
    DrawText("blocks moved",320,120,20,WHITE);
    a.position.x = (int)vectors.ConvertMousePosition.x;
    a.position.y = (int)vectors.ConvertMousePosition.y+1;
    for (auto& a : vectors.object) {

       a.selected = 0;

    }
  }
}else{
  a.color = RED;

}



}


/*  for (auto& a : vectors.object) {
a.position = vectors.ConvertRaylibScreenCoordinates(a.position,startX,startY);

}*/

for(int i = 0; i < mapRows; i++)
{
  for(int j = 0; j < mapColumns; j++)
  {
    map2d[i][j] = 0;
    for (auto& a : vectors.object) {
      if (-(i-20) == a.position.y && (j-20) == a.position.x) {
        map2d[-((int)a.position.y-20)][(int)a.position.x+20] = 1;
      }
    }




  }
}

}
void CoreClass::DrawMap2D(){


  for (auto& a : vectors.object) {
    DrawRectangleV( vectors.ConvertRaylibScreenCoordinates({a.position.x, a.position.y},startX,startY),{a.size.x,a.size.y}, a.color);
  }
  map2dX = 0;
  map2dY = 0;
  if (IsKeyDown(KEY_E)) {
    for(int i = 0; i < mapRows; i++)
    {
      for(int j = 0; j < mapColumns; j++)
      {
        DrawText(TextFormat("%d",map2d[i][j]),12+startX+map2dX,startY+map2dY,20,WHITE);
      //DrawText(TextFormat("%d,%d",i,j),12+startX+map2dX,startY+map2dY-1,2,WHITE);
        map2dX = map2dX + 25;
      }
      map2dY = map2dY + 25;
      map2dX = 0;

    }
  }
}
void CoreClass::DrawUIControls(){
  DrawRectangleV({uiRect.x,uiRect.y}, {uiRect.width,uiRect.height}, BLACK);
  DrawRectangleLinesEx(uiRect, 10, WHITE);

  //DrawText(TextFormat("Point3 distance to origin: %f", distOriginPoint3),10,10,20,WHITE);
  DrawText("---GUI---",uiRect.width/5+uiRect.x,30,20,WHITE);
  DrawText(TextFormat("grid-brightness: %.2f",fadeGrid),uiRect.width/5+uiRect.x,60,20,WHITE);
  DrawText("'O': -  'P': + ",uiRect.width/3+uiRect.x,80,10,WHITE);
  DrawText(TextFormat("FOV: %d°",(int)fov),uiRect.width/5+uiRect.x,120,20,WHITE);
  DrawText("'U': -  'I': + ",uiRect.width/3+uiRect.x,140,10,WHITE);
  DrawText(TextFormat("(%f,%f)", (float)GetMouseX(), (float)GetMouseY()),10,10,20,WHITE);
  DrawText(TextFormat("(%f,%f)", vectors.ConvertRaylibMouseCoordinateX((float)GetMouseX(),startX),vectors.ConvertRaylibMouseCoordinateY((float)GetMouseY(),startY)),10,30,20,WHITE);
  DrawText(TextFormat("Objects: %d",objectCounter),10,50,20,WHITE);
  DrawText("MAP-EDITOR --spacebar to add blocks--",320,10,20,WHITE);
  DrawText("player",convertPlayerPos.x-15,convertPlayerPos.y-20,5,{255,255,255,170});
  DrawFPS(GetScreenWidth() - uiRect.width-100, 10);
}
void CoreClass::DrawingManager(){


  BeginDrawing();


  ClearBackground(BLACK);



  vectors.DrawGrid(YELLOW, fadeGrid,startX,startY);

  DrawMap2D();

  vectors.DrawPoint({startX+1000/2,startY+1000/2},BLUE);
  vectors.DrawPoint({convertPlayerPos.x,convertPlayerPos.y},GREEN);
  DrawUIControls();
  int mapX1 = (int)((20)-(playerPos.y));
  int mapY1 = (int)((20)+(playerPos.x));
  DrawMap3D();

  EndDrawing();



}
void CoreClass::Update(){
  while (!WindowShouldClose()){
    if (IsKeyDown(KEY_P)){fadeGrid += 0.2f;}
    if (IsKeyDown(KEY_O)){ fadeGrid -= 0.2f;}
    if (fadeGrid >= 1){fadeGrid = 1;}
    if (fadeGrid <= 0){fadeGrid = 0;}
    addObject();
    UpdateMap2D();
    DrawingManager();
    objectCounter = vectors.object.size();

    /*if (IsKeyDown(KEY_A))   {
      playerAngle -= 0.05f;
      if(playerAngle < 0){
        playerAngle += 2 * PI;
      }
      playerDeltaX = cos(playerAngle)*5;
      playerDeltaY = sin(playerAngle)*5;
    }

    if (IsKeyDown(KEY_D)) {
      playerAngle += 0.05f;
      if(playerAngle > 2*PI){
        playerAngle -= 2 * PI;
      }
      playerDeltaX = cos(playerAngle)*5;
      playerDeltaY = sin(playerAngle)*5;
    }
    if (IsKeyDown(KEY_W)){
      playerPos.x+=playerDeltaX*0.005;
      playerPos.y-=playerDeltaY*0.005;
    }
    if (IsKeyDown(KEY_S)){
      playerPos.x-=playerDeltaX*0.005;
      playerPos.y+=playerDeltaY*0.005;
    }*/
    /*std::cout << "playerPosX: " << playerPos.x << '\n';
    std::cout << "playerPosY: " << playerPos.y << '\n';*/
    double rotation = 0.01*3;
    if (IsKeyPressed(KEY_R)){
      draw3Dmap = 1;
    }
    fov = (2 * atan(sqrt((planeVector.x*planeVector.x)+(planeVector.y*planeVector.y)) / sqrt((playerDirection.x*playerDirection.x)+(playerDirection.y*playerDirection.y))))*(180/PI);
      if (!IsKeyDown(KEY_U)){
        if (IsKeyDown(KEY_I)){
          if(directionLength <= 1.07){
            directionLength += 0.001;
            playerDirection.x *= directionLength;playerDirection.y *= directionLength;
          }
        }
      }

      if (!IsKeyDown(KEY_I)){
        if (IsKeyDown(KEY_U)){
          if(directionLength >= 1){
            directionLength -= 0.001;
            playerDirection.x *= 1/directionLength;playerDirection.y *= 1/directionLength;
          }


          }
      }

    if (IsKeyDown(KEY_W)){
      playerPos.x += playerDirection.x/sqrt((playerDirection.x*playerDirection.x)+(playerDirection.y*playerDirection.y)) * 0.1;
      playerPos.y += playerDirection.y/sqrt((playerDirection.x*playerDirection.x)+(playerDirection.y*playerDirection.y)) * 0.1;
    }
    if (IsKeyDown(KEY_S)){
      playerPos.x -= playerDirection.x/sqrt((playerDirection.x*playerDirection.x)+(playerDirection.y*playerDirection.y)) * 0.1;
      playerPos.y -= playerDirection.y/sqrt((playerDirection.x*playerDirection.x)+(playerDirection.y*playerDirection.y)) * 0.1;
    }
    if (IsKeyDown(KEY_D)){
      std::cout << "playerDirX: "  << playerDirection.x << '\n';
      double oldDirX = playerDirection.x;
      playerDirection.x = (playerDirection.x * cos(-rotation) - playerDirection.y * sin(-rotation));
      playerDirection.y = oldDirX * sin(-rotation) + playerDirection.y * cos(-rotation);
      double oldPlaneX = planeVector.x;
      planeVector.x = planeVector.x * cos(-rotation) - planeVector.y * sin(-rotation);
      planeVector.y = oldPlaneX * sin(-rotation) + planeVector.y * cos(-rotation);
    }
    if (IsKeyDown(KEY_A)){
      std::cout << "playerDirX: "  << playerDirection.x << '\n';
      double oldDirX = playerDirection.x;
      playerDirection.x = (playerDirection.x * cos(rotation) - playerDirection.y * sin(rotation));
      playerDirection.y = oldDirX * sin(rotation) + playerDirection.y * cos(rotation);
      double oldPlaneX = planeVector.x;
      planeVector.x = planeVector.x * cos(rotation) - planeVector.y * sin(rotation);
      planeVector.y = oldPlaneX * sin(rotation) + planeVector.y * cos(rotation);
    }
    if (IsKeyDown(KEY_RIGHT)) startX += 1.0f;
    if (IsKeyDown(KEY_LEFT))  startX -= 1.0f;
    if (IsKeyDown(KEY_UP)) startY -= 1.0f;
    if (IsKeyDown(KEY_DOWN)) startY += 1.0f;
    this->windowWidth = GetScreenWidth();
    this->windowHeight = GetScreenHeight();
    this->uiRect = {(this->windowWidth/1.28f),0,GetScreenWidth()/4.57f,GetScreenHeight()};


  }
}

CoreClass::~CoreClass() {
}
