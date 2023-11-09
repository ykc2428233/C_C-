#include "stdio.h"
int main()
{
  FILE * f = fopen("problem4.c", "r");
  int i = 1;
  char buffer[100];
  char * result;
  
  do
  {
    result = fgets(buffer, 100, f);
    printf("%d:%s", i, buffer);
    i++;
  }
  while(result != NULL);
  return(0);
}

