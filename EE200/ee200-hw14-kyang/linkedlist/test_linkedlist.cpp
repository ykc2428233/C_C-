#include "linkedlist.h"
#include <cstdio>

int main(int argc, char* argv[])
{
  // Here's some quick test code to get you started.  You'll need much more
  // thorough testing, of course.

  int arr[] = {1, 2, 3, 4, 5};
  LinkedList<int> list0(5, arr);
  for(int i = 0; i < list0.size(); i++)
  {
    std::cout << list0.getItem(i) << " ";
  }
  std::cout << std::endl;

  LinkedList<int> list1(list0);
  for(int i = 0; i < list1.size(); i++)
  {
    std::cout << list1.getItem(i) << " ";
  }
  std::cout << std::endl;

  list1.insert(99, 3);
  for(int i = 0; i < list1.size(); i++)
  {
    std::cout << list1.getItem(i) << " ";
  }
  std::cout << std::endl;

  list1.remove(3);
  for(int i = 0; i < list1.size(); i++)
  {
    std::cout << list1.getItem(i) << " ";
  }
  std::cout << std::endl;

  LinkedList<int> list2;
  list2 = list1;
  list2 = list2;
  list2.insert(88, 0);
  for(int i = 0; i < list2.size(); i++)
  {
    std::cout << list2.getItem(i) << " ";
  }
  std::cout << std::endl;

  for(int i = 0; i < list1.size(); i++)
  {
    std::cout << list1.getItem(i) << " ";
  }
  std::cout << std::endl;

  printf("***********************************\n"); 
  // Push three elements onto the front
  LinkedList<int> list;
  list.insert(1, 0);
  list.insert(2, 0);
  list.insert(3, 0);

  // Make a copy
  LinkedList<int> another = list;

  // Push some more elements onto the front of the original
  list.insert(4, 0);
  list.insert(5, 0);
  list.insert(6, 4);
  list.remove(0);

  for(int i = 0; i < list.size(); i++){
    printf(" list[%d] = %d\n", i, list.getItem(i));
  }

  for(int i = 0; i < another.size(); i++){
    printf("another[%d] = %d\n", i, another.getItem(i));
  }

  printf("***********************************\n"); 
  try
  {
    list.getItem(10); 
  }
  catch(std::exception e)
  {
      std::cout << "PROBLEM!!!" << std::endl;
  }

  return(0);
}

