
#include "problem4.h"


const char* find_shortest(const char * const * strings, int len)
{
  if( strings != NULL)
  {
    const char * shortest = NULL;
    int s_len = -1;
    for(int i = 0; i < len; i++)
    {
      if(strings[i] == NULL)
      {
        continue;
      }
      int j = 0;
      while(strings[i][j] != '\0')
      {
        j++;
      }
      if(s_len == -1 || j < s_len)
      {
        s_len = j;
        shortest = strings[i];
      }
    }
    return(shortest);
  }
  return(NULL);
}

