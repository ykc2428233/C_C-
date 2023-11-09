
#include "problem3.h"
#include "assert.h"

int main(int argc, char* argv[])
{

  int arr[] = { 7, 2, 10, 13, 15, 8, 3, 20 };
  printf("{ 7, 2, 10, 13, 15, 8, 3, 20 }\n");
  assert(find_sequence(arr, 8) == &arr[1]);

  int arr1[] = { 7, 2, 1 };
  printf("{ 7, 2, 1 }\n");
  assert(find_sequence(arr1, 3) == NULL);

  int arr2[] = { 9, 10, 23, 87, 234, 56, 78, 98, 1000, 100 };
  printf("{ 9, 10, 23, 87, 234, 56, 78, 98, 1000, 100 }\n");
  assert(find_sequence(arr2, 10) == &arr2[0]);

  int arr3[] = {2};
  printf("{2}\n");
  assert(find_sequence(arr3, 1) == NULL);

  int arr4[] = { 9, 10, 23, 87, -234, 56, 78, 98, 1000, 100 };
  printf("{ 9, 10, 23, 87, -234, 56, 78, 98, 1000, 100 }\n");
  assert(find_sequence(arr4, 10) == &arr4[4]);

  assert(find_sequence(NULL, 10) == NULL);
  return(0);
}

