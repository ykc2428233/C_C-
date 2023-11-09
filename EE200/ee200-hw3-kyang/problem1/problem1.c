
#include "problem1.h"
#include "stdio.h"

int print_factors(int n)
{
  if( n <= 1)
  {
    return(-1);
  }
  else
  {
    for(int factor = 2; factor*factor <= n; factor++)
    {
      while( n % factor == 0)
      {
        printf("%d ", factor);
        n = n / factor;
      } 
    }
    printf("%d\n", n);
    return(0); 
  }
}

