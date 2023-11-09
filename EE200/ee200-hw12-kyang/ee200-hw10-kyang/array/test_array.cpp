#include "array.h"
#include <cstdio>
#include <assert.h>

int main(int argc, char* argv[])
{
  // Here's some quick test code to get you started.  You'll need much more
  // thorough testing, of course.

  
// int test
  int arr[3] = {1, 2, 3};  

  Array<int> rtoo0; //NULL
  Array<int> rtoo1(rtoo0);
  Array<int> rtoo2(10, 2);
  Array<int> rtoo3(3, 1);
  Array<int> rtoo4(3, arr);
 
  rtoo0.append(1);
  assert(rtoo0[0] == 1 && rtoo0.size() == 1);
  rtoo0.append(rtoo2);
  assert(rtoo0[10] == 2 && rtoo0.size() == 11);
  std::cout << rtoo0 << std::endl;

  rtoo0 = rtoo0 + rtoo1 + rtoo2 + rtoo3 + rtoo4;  
  std::cout << rtoo0 << std::endl;
  assert(rtoo0[23] == 1 && rtoo0.size() == 27 && rtoo0[26] == 3);
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
// float test
  float arrf[3] = {1.111, 2.222, 3.333};  

  Array<float> rtoof0; //NULL
  Array<float> rtoof1(rtoof0);
  Array<float> rtoof2(10, 2.222);
  Array<float> rtoof3(3, 1.111);
  Array<float> rtoof4(3, arrf);
 
  rtoof0.append(1.111);
  assert(rtoof0[0]-1.111<0.0001 && rtoof0.size() == 1);
  rtoof0.append(rtoof2);
  assert(rtoof0[10]-2.222<0.0001 && rtoof0.size() == 11);
  std::cout << rtoof0 << std::endl;

  rtoof0 = rtoof0 + rtoof1 + rtoof2 + rtoof3 + rtoof4;  
  std::cout << rtoof0 << std::endl;
  assert(rtoof0[23]-1.111<0.0001 && rtoof0.size() == 27 && rtoof0[26]-3.333<0.0001);
  std::cout << rtoof4 << std::endl;
  
  for(int i = 0; i < rtoof0.size(); i++){
    printf("rtoof0[%d] = %f\n", i, rtoof0[i]);
  }

  for(int i = 0; i < rtoof1.size(); i++){
    printf("rtoof1[%d] = %f\n", i, rtoof1[i]);
  }
  
  for(int i = 0; i < rtoof2.size(); i++){
    printf("rtoof2[%d] = %f\n", i, rtoof2[i]);
  }

  for(int i = 0; i < rtoof3.size(); i++){
    printf("rtoof3[%d] = %f\n", i, rtoof3[i]);
  }

  for(int i = 0; i < rtoof4.size(); i++){
    printf("rtoof4[%d] = %f\n", i, rtoof4[i]);
  }

// char test
  char arrc[3] = {'a', 'b', 'c'};  

  Array<char> rtooc0; //NULL
  Array<char> rtooc1(rtooc0);
  Array<char> rtooc2(10, 'd');
  Array<char> rtooc3(3, 'e');
  Array<char> rtooc4(3, arrc);
 
  rtooc0.append('a');
  assert(rtooc0[0] == 'a' && rtooc0.size() == 1);
  rtooc0.append(rtooc2);
  assert(rtooc0[10] == 'd' && rtooc0.size() == 11);
  std::cout << rtooc0 << std::endl;

  rtooc0 = rtooc0 + rtooc1 + rtooc2 + rtooc3 + rtooc4;  
  std::cout << rtooc0 << std::endl;
  assert(rtooc0[23] == 'e' && rtooc0.size() == 27 && rtooc0[26]=='c');
  std::cout << rtooc4 << std::endl;
  
  for(int i = 0; i < rtooc0.size(); i++){
    printf("rtooc0[%d] = %c\n", i, rtooc0[i]);
  }

  for(int i = 0; i < rtooc1.size(); i++){
    printf("rtooc1[%d] = %c\n", i, rtooc1[i]);
  }
  
  for(int i = 0; i < rtooc2.size(); i++){
    printf("rtooc2[%d] = %c\n", i, rtooc2[i]);
  }

  for(int i = 0; i < rtooc3.size(); i++){
    printf("rtooc3[%d] = %c\n", i, rtooc3[i]);
  }

  for(int i = 0; i < rtooc4.size(); i++){
    printf("rtooc4[%d] = %c\n", i, rtooc4[i]);
  } 

  return(0);
}

