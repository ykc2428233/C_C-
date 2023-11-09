
#include "problem2.h"


int* find_min(int* array, int n)
{
  if(n == 0 || array == NULL )
  {
    return(NULL);
  }
  else if(n > 0)
  {
    int * min = &array[0];
    for( int i = 1; i < n; i++ )
    {
      min = *min > array[i] ? &array[i] : min;
    }
    return(min);
  }
  return(0);
}

