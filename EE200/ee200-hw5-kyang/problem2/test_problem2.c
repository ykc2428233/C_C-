
#include "problem2.h"
#include "assert.h"

int main(int argc, char* argv[])
{
  int array[] = {9, 10, 20, -932, 84, -5};
  assert(*find_min(array, 6)==-932);
  
  int array2[] = {-9, 0, 20, 932, 84, -5};
  assert(*find_min(array2, 6)==-9);
  
  //int array1[2] = {NULL};
  assert(find_min(NULL, 1)==NULL);

  int array3[] = {0, 1};
  assert(find_min(array3, -1)==0);
  
  return(0);
}

