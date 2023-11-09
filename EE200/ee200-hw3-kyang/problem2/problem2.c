
#include "problem2.h"
#include "math.h"
#include "stdio.h"

int find_power(int n)
{
  if ( n <= 0 )
  {
    return(0);
  }
  else
  {
    int power = log2(n);
    int rsl = pow(2, power);
    return(rsl); 
  }
}

