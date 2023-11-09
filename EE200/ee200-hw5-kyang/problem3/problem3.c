
#include "problem3.h"

int* find_sequence(int* seq, int n)
{
  if( seq == NULL)
  {
    return(NULL);
  }
  int length[n];
  for(int i = 0; i < n; i++)
  {
    length[i] = 1;
  }
  
  for(int j = 0; j < n-1; j++)
  {
    if(seq[j] < seq[j+1])
    {
      length[j+1] = length[j] + 1;
    }
  }
  
  int * max_l = length;
  
  for( int k = 1; k < n; k++)
  {
    max_l = *max_l < length[k] ? &length[k] : max_l;
  }
  printf("The max length is %d, ", *max_l);
  if(*max_l < 2)
  {
    printf("No sequences\n");
    return(NULL);
  }
  else
  {
    int * beginning = &seq[ max_l - length - *max_l + 1];
    printf("Start from %d\n", *beginning);
    return(beginning); 
  }
}

