#include "core.h"

CoreClass::CoreClass(){
  vectors.rectangleSelected = 0;

   VectorClass::Objects objects[MAX_OBJECTS] = {   {{-10,-2}, {25,25},RED,0},{{-4, -2}, {25,25},RED,0}   };
   for (int i = 0; i < sizeof(objects) / sizeof(objects[0]); i++) {
       vectors.object.push_back(objects[i]);
   }

   objectCounter = sizeof(objects);


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

  if (key == 32 )  {

    VectorClass::Objects new_object = {{(int)vectors.ConvertMousePosition.x,(int)vectors.ConvertMousePosition.y},{25,25},RED,0};
    vectors.object.push_back(new_object);
  }

}
void CoreClass::UpdateMap2D(){


  vectors.ConvertMousePosition = {vectors.ConvertRaylibMouseCoordinateX((float)GetMouseX()),vectors.ConvertRaylibMouseCoordinateY((float)GetMouseY())};
  Vector2 convertRectangle;

  for (auto& a : vectors.object) {


       if(IsMouseButtonUp(MOUSE_BUTTON_LEFT)){
         vectors.rectangleSelected = 0;
         for (auto& a : vectors.object) {

           a.selected = 0;

         }
       }
    if(vectors.rectangleSelected == 0 && CheckCollisionPointRec(vectors.ConvertMousePosition,{a.position.x,a.position.y,a.size.x/30,a.size.y/30})){
      a.color = YELLOW;

          a.selected = 1;

    }else{
      a.color = RED;

    }


  }
  for (auto& a : vectors.object){
    if(  a.selected == 1 &&  IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
      vectors.rectangleSelected = 1;
      a.position.x = (int)vectors.ConvertMousePosition.x;
      a.position.y = (int)vectors.ConvertMousePosition.y;

    }
  }



}
void CoreClass::DrawMap2D(){
  for (auto& a : vectors.object) {
    DrawRectangleV( vectors.ConvertRaylibScreenCoordinates({a.position.x, a.position.y}),{a.size.x,a.size.y}, a.color);
  }
}
void CoreClass::DrawUIControls(){

  DrawRectangleLinesEx(uiRect, 10, WHITE);

  //DrawText(TextFormat("Point3 distance to origin: %f", distOriginPoint3),10,10,20,WHITE);
  DrawText("---GUI---",uiRect.width/5+uiRect.x,30,20,WHITE);
    DrawText(TextFormat("grid-brightness: %.2f",fadeGrid),uiRect.width/5+uiRect.x,60,20,WHITE);
      DrawText("ARROW_DOWN: -  ARROW_UP: + ",uiRect.width/3+uiRect.x,80,10,WHITE);
  DrawText(TextFormat("(%f,%f)", (float)GetMouseX(), (float)GetMouseY()),10,10,20,WHITE);
  DrawText(TextFormat("(%f,%f)", vectors.ConvertRaylibMouseCoordinateX((float)GetMouseX()),vectors.ConvertRaylibMouseCoordinateY((float)GetMouseY())),10,30,20,WHITE);
  DrawText("MAP-EDITOR --spacebar to add blocks--",320,10,20,WHITE);
}
void CoreClass::DrawingManager(){


  BeginDrawing();


  ClearBackground(BLACK);



  vectors.DrawGrid(YELLOW, fadeGrid);
  vectors.DrawPoint({500,500},BLUE);
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
  }
}

CoreClass::~CoreClass() {
}
