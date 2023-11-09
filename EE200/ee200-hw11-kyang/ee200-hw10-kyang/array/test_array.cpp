#include "array.h"
#include <cstdio>
#include <assert.h>

int main(int argc, char* argv[])
{
  // Here's some quick test code to get you started.  You'll need much more
  // thorough testing, of course.

  
  int arr[3] = {1, 2, 3};  

  Array rtoo0(1,0); //{0}
  Array rtoo1(rtoo0);
  Array rtoo2(10, 2);
  Array rtoo3(3, 1);
  Array rtoo4(3, arr);
 
  rtoo0.append(1);
  assert(rtoo0[0] == 0 && rtoo0[1] == 1 && rtoo0.size() == 2);
  rtoo0.append(rtoo2);
  assert(rtoo0[11] == 2 && rtoo0.size() == 12);
  std::cout << rtoo0 << std::endl;

  rtoo0 = rtoo0 + rtoo1 + rtoo2 + rtoo3 + rtoo4;  
  assert(rtoo0[25] == 1 && rtoo0.size() == 29 && rtoo0[28] == 3);
  std::cout << rtoo0 << std::endl;
  std::cout << rtoo4 << std::endl;
  
  for(int i = 0; i < rtoo0.size(); i++){
    printf("rtoo0[%d] = %d\n", i, rtoo0[i]);
  }

  for(int i = 0; i < rtoo1.size(); i++){
    printf("rtoo1[%d] = %d\n", i, rtoo1[i]);
  }
  
  for(int i = 0; i < rtoo2.size(); i++){
    printf("rtoo2[%d] = %d\n", i, rtoo2[i]);
  }

  for(int i = 0; i < rtoo3.size(); i++){
    printf("rtoo3[%d] = %d\n", i, rtoo3[i]);
  }

  for(int i = 0; i < rtoo4.size(); i++){
    printf("rtoo4[%d] = %d\n", i, rtoo4[i]);
  }

  //Array rtoo5(-1, arr);
  Array rtoo5;
  assert(rtoo5.size()==0);
  return(0);
}

