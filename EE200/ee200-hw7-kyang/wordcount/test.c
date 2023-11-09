#include <stdio.h>

int main()
{
  FILE *f = fopen("problem3.c", "r");
  printf("%s\n", stdout);  
  fclose(f);
  return(0);
}
