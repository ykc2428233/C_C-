
#include "problem3.h"


int main(int argc, char* argv[])
{

  // Put anything here that you think is appropriate to test your function
  // You can define triangles here, since the struct is declared in the header

  Triangle t1;

  t1.a.x = 1;
  t1.a.y = 3;
  t1.b.x = 2;
  t1.b.y = 2;
  t1.c.x = 3;
  t1.c.y = 9;
  
  Triangle t2;
  
  t2.a.x = -1;
  t2.a.y = -3;
  t2.b.x = -2;
  t2.b.y = -2;
  t2.c.x = -3;
  t2.c.y = -9;
  
  Triangle * t1_p = &t1;  
  Triangle * t2_p = &t2;  
 
  assert( getLarger(t1_p, t2_p) ==  &(t1) );
  
  t2.a.x = 10;
  t2.a.y = 15;
  t2.b.x = -2;
  t2.b.y = -2;
  t2.c.x = -3;
  t2.c.y = -9;
  
  assert( getLarger(t1_p, t2_p) ==  &(t2) );
  
  t1.a.x = 100;
  t1.a.y = 1;
  t1.b.x = 2;
  t1.b.y = 2;
  t1.c.x = 3;
  t1.c.y = 3;
  
  assert( getLarger(t1_p, t2_p) ==  &(t1) );
  
  Triangle * tn_p;
  tn_p = NULL;
  
  assert( getLarger(tn_p, t2_p) ==  &(t2) );
  
  assert( getLarger(t1_p, tn_p) ==  &(t1) );
  
  assert( getLarger(tn_p, tn_p) ==  NULL );
  
  return(0);
}

