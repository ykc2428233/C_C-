
#include "problem5.h"
#include "stdlib.h"
#include "stdio.h"

void print_random(int n, int max)
{
  if ( max > 0 && n > 0 )
  {
    int ran = 0;
    for( int i = 0; i < n;)
    {
      ran = rand();
      if( ran != RAND_MAX )
      {
        ran = ( ( ran / (float) RAND_MAX) * max);
        if( i == n-1 )
        {
          printf("%d\n", ran);
        }
        else
        {
          printf("%d ", ran);
        }
        i++;
      }
    }
  }
}

