#include "array.h"
#include <cstdio>
#include <assert.h>
#include <iostream>

int main(int argc, char* argv[])
{
  // Here's some quick test code to get you started.  You'll need much more
  // thorough testing, of course.

  Array arr;
  arr.initialize(10, 5);
  arr.append(20);
  assert(arr.size()==11);
  assert(arr[10] == 20);
  Array one;
  one.initialize(10, 1);
  arr.append(one);
  assert(arr[11] == 1);
  assert(arr.size()==21);

  Array rtoo;
  rtoo.initialize(0, 0);
  Array rtoo1;
  rtoo1.initialize(0, 0);
  rtoo = rtoo1 = arr;
  rtoo[3] = rtoo1[4] = 256;
  assert(rtoo[3] == 256 && rtoo1[4] == 256);
  
  for(int i = 0; i < arr.size(); i++){
    arr[i] = i * 2;
  }


  for(int i = 0; i < arr.size(); i++){
    printf(" arr[%d] = %d\n", i, arr[i]);
  }

  for(int i = 0; i < rtoo.size(); i++){
    printf("rtoo[%d] = %d\n", i, rtoo[i]);
  }

  for(int i = 0; i < rtoo1.size(); i++){
    printf("rtoo1[%d] = %d\n", i, rtoo1[i]);
  }
  
  arr.cleanup();
  one.cleanup();
  rtoo.cleanup();
  rtoo1.cleanup();
  std::cout << rtoo1[rtoo1.size()] << std::endl;

  return(0);
}

