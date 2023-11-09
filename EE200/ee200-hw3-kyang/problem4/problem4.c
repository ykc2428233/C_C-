
#include "problem4.h"
#include "math.h"
#include "stdio.h"

Triangle getLarger(Triangle first, Triangle second)
{
  Triangle t;
  double area_first, area_second;
  area_first = fabs(((first.a.x * first.b.y - first.b.x * first.a.y) + (first.b.x * first.c.y - first.c.x * first.b.y) + (first.c.x * first.a.y - first.a.x * first.c.y)) / 2); 
  area_second = fabs(((second.a.x * second.b.y - second.b.x * second.a.y) + (second.b.x * second.c.y - second.c.x * second.b.y) + (second.c.x * second.a.y - second.a.x * second.c.y)) / 2);
  
  if( fabs(area_first - area_second) < 0.0000000000000001 )
  {
    t = first;
  }
  else if( area_first < area_second )
  {
    t = second;
  }
  else
  {
    t = first;
  }
  
  return(t); 
}

