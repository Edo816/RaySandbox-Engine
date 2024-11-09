#include "core.h"


VectorClass::VectorClass(){

  screenWidth = 800;
  screenHeight = 800;
  Point1 = {(float)10 , (float)10};
  Point2 = {(float)10 , (float)-2};
  currentMode = 1;

}



Vector2 VectorClass::VectorProjection(Vector2 pointNormalized, float scalarProjection){

  Vector2  VectorProjection = {pointNormalized.x*(scalarProjection),pointNormalized.y*(scalarProjection)};
  return VectorProjection;

}


float VectorClass::ScalarDotProductProjection(Vector2 pointNormalized, Vector2 point){



  return (pointNormalized.x * point.x) + (pointNormalized.y * point.y);

}


float  VectorClass::vectorPointLength(Vector2 point){

  return sqrt((point.x*point.x) + (point.y * point.y));
}


float VectorClass::ConvertRaylibMouseCoordinateX(float x, int startX){


  float x1 = ((float)GetMouseX() - (GetScreenWidth()-((GetScreenWidth()/100)*21.88f)+startX)/2)/25;
  return x1;
}
float VectorClass::ConvertRaylibMouseCoordinateY(float y, int startY){



  float y1 = (-((float)GetMouseY() - (GetScreenHeight()+280)/ 2))/25;
  return y1;
}
float VectorClass::ConvertRaylibScreenRadius(float radius){


  radius = radius*25;
  return radius;
}

Vector2 VectorClass::ConvertRaylibScreenCoordinates(Vector2 xy){


  xy.x = (GetScreenWidth() / 2-150+10) + (xy.x)*25;
  xy.y = (GetScreenHeight() / 2+150-35) + (-(xy.y))*25;
  return xy;
}


Vector2 VectorClass::ReflectRay(Vector2 Dir, Vector2 n){
  float dotProductProjection = (Dir.x*n.x)+(Dir.y*n.y);
  return {Dir.x - 2 * dotProductProjection * n.x, Dir.y - 2 * dotProductProjection * n.y};
}

void VectorClass::DrawGrid(Color color, float fade, int startX, int startY){
  for(int y = startY; y < 1000+startY; y+=25){
    for (int x = startX; x < 1000+startX; x+=25) {
      DrawRectangleLines(x,y,25,25,Fade(color, fade));
      DrawRectangleV({x,y},{24,24},Fade(GRAY, fade));
    }
  }
}


void VectorClass::DrawPoint(Vector2 origin,Color color){
  DrawCircleV(origin,10,color);


}


/*void VectorClass::MovePoint(){


if(currentMode == 1){
  if (CheckCollisionPointCircle(Point1,ConvertMousePosition,2)){
    color1 = YELLOW;
    selectedPoint = 1;


  }
  if (CheckCollisionPointCircle(Point2,ConvertMousePosition,2)){
    color2 = YELLOW;
    selectedPoint = 2;
  }

}
if(currentMode == 2){
  if (CheckCollisionPointCircle(Point3,ConvertMousePosition,2)){
      color3 = YELLOW;
      selectedPoint = 3;
    }

}
if(currentMode == 3){
  if (CheckCollisionPointCircle(Point4,ConvertMousePosition,2)){
      color4 = YELLOW;
      selectedPoint = 4;
    }

}
  switch(selectedPoint){
    case 1:
      if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        Point1 = ConvertMousePosition;

      }
      break;
    case 2:
      if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        Point2 = ConvertMousePosition;

      }
      break;
    case 3:
      if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
        Point3 = ConvertMousePosition;

      }
    case 4:
      if(IsMouseButtonDown(MOUSE_BUTTON_LEFT)){
          Point4 = {(int)ConvertMousePosition.x,(int)ConvertMousePosition.y};

      }
      break;
    default:
      break;
  }
}


void VectorClass::Update(){



  getKey = GetKeyPressed();
  if(getKey == 49){
    currentMode = 1;
  }
  if(getKey == 50){
    currentMode = 2;
  }
  if(getKey == 51){
    currentMode = 3;
  }
  if(currentMode == 1){
    vectorsUpdate();

  }

}
void VectorClass::vectorsUpdate(){

  color1 = RED;
  color2 = BLUE;
  color3 = BLUE;
  selectedPoint = 0;
  originX = GetScreenWidth() / 2;
  originY = GetScreenHeight() / 2;
  origin = {(float)originX , (float)originY};
  Point1Normalized = {Point1.x / vectorPointLength(Point1) , Point1.y / vectorPointLength(Point1)};
  ConvertMousePosition = {ConvertRaylibMouseCoordinateX((float)GetMouseX()),ConvertRaylibMouseCoordinateY((float)GetMouseY())};
  scalarProjection = ScalarDotProductProjection(Point1Normalized,Point2);
  MovePoint();
  BeginDrawing();

  ClearBackground(BLACK);

  DrawGrid(GREEN, 0.2f);
  DrawPoint(origin,RED);
  DrawPoint(ConvertRaylibScreenCoordinates(Point1),color1);
  DrawPoint(ConvertRaylibScreenCoordinates(Point1Normalized),color1);
  DrawPoint(ConvertRaylibScreenCoordinates(VectorProjection(Point1Normalized,scalarProjection)),color1);
  DrawLineV(origin,ConvertRaylibScreenCoordinates(Point1),color1);
  DrawPoint(ConvertRaylibScreenCoordinates(Point2),color2);
  DrawLineV(origin,ConvertRaylibScreenCoordinates(Point2),color2);
  DrawText(TextFormat("(%f,%f)", (float)GetMouseX(), (float)GetMouseY()),10,10,20,WHITE);
  DrawText(TextFormat("(%f,%f)", ConvertRaylibMouseCoordinateX((float)GetMouseX()),ConvertRaylibMouseCoordinateY((float)GetMouseY())),10,30,20,WHITE);
  DrawText(TextFormat("Point1 Normalized = (%f,%f)", Point1Normalized.x, Point1Normalized.y),10,50,20,WHITE);
  DrawText(TextFormat("Scalar Dot Product Projection = %f", scalarProjection),10,70,20,WHITE);
  EndDrawing();




}*/
VectorClass::~VectorClass() {

}
