#include "array.h"
#include <cstdio>

int main(int argc, char* argv[])
{
  // Here's some quick test code to get you started.  You'll need much more
  // thorough testing, of course.

  int a[3] = {1, 2, 3};  

  Array rtoo0;
  Array rtoo1(rtoo0);
  Array rtoo2(10, 2);
  Array rtoo3(3, 1);
  Array rtoo4(3, a);
 
  rtoo0.append(1);
  rtoo0.append(rtoo2);
  std::cout << rtoo0 << std::endl;

  rtoo0 = rtoo0 + rtoo1 + rtoo2 + rtoo3;  
  std::cout << rtoo0 << std::endl;
  
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


  return(0);
}

