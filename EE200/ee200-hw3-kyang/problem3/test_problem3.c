
#include "problem3.h"
#include "stdio.h"
#include "assert.h"


int main(int argc, char* argv[])
{
  assert( calculate(1, '+', 37) == 38 );
  assert( calculate(2, '-', 90) == -88 );
  assert( fabs(calculate(56.32, '*', 23.96) - 1349.4272) < 0.000001 );
  assert( calculate(-9, '/', 0) == 0 );
  assert( fabs(calculate(-9, '/', -32) - 0.28125) < 0.000001);
  assert( calculate(2, '^', 10) == 1024); 
  assert( calculate(0, '^', -32) == 0); 
  assert( calculate(0, '^', 0) == 0); 
  assert( calculate(-3, '^', 2.97) == 0); 
  assert( calculate(-3, '?', 2.97) == 0); 
  return(0);
}

