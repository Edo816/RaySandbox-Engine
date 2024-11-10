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
   VectorClass::Objects objects[MAX_OBJECTS] = {   {{-10,-2}, {25,25},RED,0},{{-4, -2}, {25,25},RED,0}   };
   for (int i = 0; i < 2; i++) {
       vectors.object.push_back(objects[i]);
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
void CoreClass::addObject(){
  int key = GetKeyPressed();
  highlightRec.x = (int)vectors.ConvertMousePosition.x;
  highlightRec.y = (int)vectors.ConvertMousePosition.y+1;
  DrawRectangleV( vectors.ConvertRaylibScreenCoordinates({highlightRec.x, highlightRec.y},startX,startY),{highlightRec.width,highlightRec.height},YELLOW);

  for (auto& a : vectors.object) {
    if((int)vectors.ConvertMousePosition.x==a.position.x&&(int)vectors.ConvertMousePosition.y+1==a.position.y){
      place = 1;
    }
  }
  if (key == 32 && place == 0)  {

      VectorClass::Objects new_object = {{(int)vectors.ConvertMousePosition.x,(int)vectors.ConvertMousePosition.y+1},{25,25},RED,0};
      vectors.object.push_back(new_object);
      place = 1;

    }

    place = 0;


}

void CoreClass::UpdateMap2D(){


  vectors.ConvertMousePosition = {vectors.ConvertRaylibMouseCoordinateX((float)GetMouseX(),startX),vectors.ConvertRaylibMouseCoordinateY((float)GetMouseY(),startY)};
  Vector2 convertRectangle;

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
          a.position.x = (int)vectors.ConvertMousePosition.x;
          a.position.y = (int)vectors.ConvertMousePosition.y+1;
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
        std::cout << "isSelected: " << isSelected << '\n';
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

}
void CoreClass::DrawMap2D(){
  for (auto& a : vectors.object) {
    DrawRectangleV( vectors.ConvertRaylibScreenCoordinates({a.position.x, a.position.y},startX,startY),{a.size.x,a.size.y}, a.color);
  }
}
void CoreClass::DrawUIControls(){
  DrawRectangleV({uiRect.x,uiRect.y}, {uiRect.width,uiRect.height}, BLACK);
  DrawRectangleLinesEx(uiRect, 10, WHITE);

  //DrawText(TextFormat("Point3 distance to origin: %f", distOriginPoint3),10,10,20,WHITE);
  DrawText("---GUI---",uiRect.width/5+uiRect.x,30,20,WHITE);
    DrawText(TextFormat("grid-brightness: %.2f",fadeGrid),uiRect.width/5+uiRect.x,60,20,WHITE);
      DrawText("ARROW_DOWN: -  ARROW_UP: + ",uiRect.width/3+uiRect.x,80,10,WHITE);
  DrawText(TextFormat("(%f,%f)", (float)GetMouseX(), (float)GetMouseY()),10,10,20,WHITE);
  DrawText(TextFormat("(%f,%f)", vectors.ConvertRaylibMouseCoordinateX((float)GetMouseX(),startX),vectors.ConvertRaylibMouseCoordinateY((float)GetMouseY(),startY)),10,30,20,WHITE);
  DrawText(TextFormat("Objects: %d",objectCounter),10,50,20,WHITE);
  DrawText("MAP-EDITOR --spacebar to add blocks--",320,10,20,WHITE);
}
void CoreClass::DrawingManager(){


  BeginDrawing();


  ClearBackground(BLACK);



  vectors.DrawGrid(YELLOW, fadeGrid,startX,startY);
  vectors.DrawPoint({startX+1000/2,startY+1000/2},BLUE);
  DrawMap2D();
  DrawUIControls();
  EndDrawing();



}
void CoreClass::Update(){
  while (!WindowShouldClose()){
    if (IsKeyDown(KEY_UP)){fadeGrid += 0.2f;}
    if (IsKeyDown(KEY_DOWN)){ fadeGrid -= 0.2f;}
    if (fadeGrid >= 1){fadeGrid = 1;}
    if (fadeGrid <= 0){fadeGrid = 0;}
    addObject();
    UpdateMap2D();
    DrawingManager();
    objectCounter = vectors.object.size();
    if (IsKeyDown(KEY_D)) startX += 1.0f;
    if (IsKeyDown(KEY_A))  startX -= 1.0f;
    if (IsKeyDown(KEY_W)) startY -= 1.0f;
    if (IsKeyDown(KEY_S)) startY += 1.0f;
    this->windowWidth = GetScreenWidth();
    this->windowHeight = GetScreenHeight();
    this->uiRect = {(this->windowWidth/1.28f),0,GetScreenWidth()/4.57f,GetScreenHeight()};


  }
}

CoreClass::~CoreClass() {
}
