
#include "problem4.h"
#include "stdio.h"
#include "assert.h"
#include "math.h"

int main(int argc, char* argv[])
{
  Triangle t1;
  t1.a.x = 1;
  t1.a.y = 1;
  t1.b.x = 1;
  t1.b.y = 1;
  t1.c.x = 1;
  t1.c.y = 1;

  Triangle t2;
  t2.a.x = -1;
  t2.a.y = -2;
  t2.b.x = -2;
  t2.b.y = -4;
  t2.c.x = -3;
  t2.c.y = -6;
  
  assert(fabs(getLarger(t1, t2).a.x - t1.a.x) < 0.0000000000000001);

  t2.a.x = 10;
  t2.a.y = 15;
  t2.b.x = -2;
  t2.b.y = -2;
  t2.c.x = -3;
  t2.c.y = -9;
  
  assert(fabs(getLarger(t1, t2).a.x - t2.a.x) < 0.0000000000000001);
  
  t1.a.x = 100;
  t1.a.y = 1;
  t1.b.x = 2;
  t1.b.y = 2;
  t1.c.x = 3;
  t1.c.y = 3;
  
  assert(fabs(getLarger(t1, t2).a.x - t1.a.x) < 0.0000000000000001);
  return(0);
}

