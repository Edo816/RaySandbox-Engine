#ifndef VECTORCLASS_H
#define VECTORCLASS_H


class VectorClass
{

private:

  Vector2 Point1;
  Vector2 Point2;
  Vector2 Point3;
  Vector2 Point4;
  Color color1;
  Color color2;
  Color color3;
  Color color4;
  float originX;
  float originY;
  Vector2 origin;
  int selectedPoint;
  Vector2 Point1Normalized;
  float scalarProjection;
  int currentMode;
  int getKey;



  float radius;
  int isInside;


  struct Rays{

    Vector2 RayUnitStepSize;
    Vector2 MapCheck;
    Vector2 RayLenght1D;
    Vector2 Step;
    Vector2 RectanglePoint;
    Vector2 RayDir;
    Vector2 RayDir1;
    bool RectangleFound;
    float Distance;
    float slope;
    Vector2 MapCheckNormalized;
    float scalarNormalProjection;
    Vector2 NormalProjection;
    Vector2 reflected;
    Vector2 startingPoint;
    int id;
  };
  std::vector<Rays> ray;
  int count;
  Vector2 MapCheck1;
  Vector2 startingPoint1;
  int reflect;
  int count1;
public:
  VectorClass();

  ~VectorClass();
   int screenWidth;
   int screenHeight;
   Vector2 VectorProjection(Vector2 pointNormalized, float scalarProjection);
   float ScalarDotProductProjection(Vector2 pointNormalized, Vector2 point);
   float  vectorPointLength(Vector2 point);
   float ConvertRaylibMouseCoordinateX(float x, int startX);
   float ConvertRaylibMouseCoordinateY(float y, int startY);
   Vector2 ConvertRaylibScreenCoordinates(Vector2 xy);
   float ConvertRaylibScreenRadius(float radius);
   Vector2 ReflectRay(Vector2 Dir, Vector2 n);
   void DrawGrid(Color color, float fade, int startX, int startY);
   void DrawPoint(Vector2 origin,Color color);
   void MovePoint();
   void Update();
   void vectorsUpdate();
   int rectangleSelected;
   struct Objects{

     Vector2 position;
     Vector2 size;
     Color color;
     int selected;

   };
   std::vector<Objects> object;
   Vector2 ConvertMousePosition;

};
#endif
