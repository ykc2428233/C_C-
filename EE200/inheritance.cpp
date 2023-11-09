#include <cstdio>
#include <cstdlib>

class Shape {
public:
  Shape() {
    xPos = 2;
    yPos = 2;
  }
  virtual void draw() = 0;
  //{
  //  printf("Drawing generic shape\n");
  //}
  double perimeter()
  {
    return(0);
  }
  double getX() { return xPos; }
  double getY() { return yPos; }

protected: //always protected for inheritance
  double xPos;
  double yPos;
};

class Triangle : public Shape {  //default private 
public:
  Triangle() {
    xPos = 5;
    yPos = 5;
  }
  void draw(){
    printf("This is a Triangle\n");
  }
};

int main(int argc, char* argv[])
{
/*
  Shape* s = new Shape;
  s->draw();
  printf("The x-coordinate of s is %lg\n", s->getX()); 
  
  Triangle* t = new Triangle;
  t->draw();
  
  printf("The x-coordinate of t is %lg\n", t->getX()); 
  
  delete s;
  delete t;
*/
  Shape* r = new Triangle;
  r->draw();
  delete r;

  //Shape* allToDraw[100];
  return(0);
}
