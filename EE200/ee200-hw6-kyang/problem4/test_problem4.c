
#include "problem4.h"
#include "assert.h"

int main(int argc, char* argv[])
{
  const char * str[] = { "erutidsfj sd?gqr", "weu327hgjyd*73 8", "ah3&&", "?asdfg64", "1273j", "  1" };
  printf("->%s<-\n", find_shortest(str, 6));

  assert(find_shortest(NULL, 6)==NULL);
  
  const char * str1[] = { "erutidsfj sd?gqr", "weu327hgjyd*73 8", "ah3&&", "?asdfg64", "1273j", "  1", NULL, "1"};
  printf("->%s<-\n", find_shortest(str1, 8));

  const char * str2[] = {NULL, NULL, NULL};
  assert(find_shortest(str2, 3) == NULL);

  const char * str3[] = { NULL, "weu327hgjyd*73 8", "NULL", "?asdfg64", "1273j", NULL, "kdsjfkja"};
  printf("->%s<-\n", find_shortest(str3, 7));

  const char * str4[] = { "", "weu327hgjyd*73 8", "NULL", "?asdfg64", "1273j", NULL, "kdsjfkja"};
  printf("->%s<-\n", find_shortest(str4, 7));

  return(0);
}

