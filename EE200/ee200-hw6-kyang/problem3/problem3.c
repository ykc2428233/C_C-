
#include "problem3.h"

void find_frequency(const char* str, int len, unsigned int histogram[26])
{
  if( str == NULL || histogram == NULL)
  {
    printf("error:Missing String or Histogram!!!\n");
  }	
  else
  { 
    for(int i = 0; i < 26; i++)
    {
      histogram[i] = 0;
    }
    for( int i = 0; i < len; i++)
    {
      //printf("%d\n", i);
      if(str[i] == '\0')
      {
       break;
      }
      if((str[i]>=65 && str[i]<=90) || (str[i]>=97 && str[i]<=122))
      {
        histogram[str[i]%32-1]++;
      }
    }
  }
}

