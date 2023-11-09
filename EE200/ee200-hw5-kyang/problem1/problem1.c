
#include "problem1.h"
#include "stdio.h"

void linspace(double* array, double min, double max, int n)
{
  if(n >= 1 && array != NULL)
  {
    // Fill in this function
    double diff = n == 1 ? 0.0 : (max - min)/(n - 1);
    for( int i = 0; i < n; i++ )
    {
      array[i] = min + diff * i;
      printf("%f ", array[i]);
    }
    printf("\n");
  }
}

