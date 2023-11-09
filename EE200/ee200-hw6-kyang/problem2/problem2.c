
#include "problem2.h"
#include "stdio.h"

void lower(char* str)
{
  int i = 0;
  while(str)
  {	  
    if(str[i] == '\0')
    {
      break;
    }
    else
    {
      if(str[i] >= 65 && str[i] <= 90)
      {
        str[i] = (char)((int)str[i]+32);
      }
      i++;
    }
  }
}

