#include <cstdio>
#include <assert.h>
#include "btree.h"

int main(int argc, char* argv[])
{
  //single tree tests
  BTree bt0;
  
  //empty tree & default constructor
  assert(bt0.size()==0);
  assert(!bt0.mRoot);
  assert(!bt0.contains(1));
  int* arr0 = bt0.toArray();
  assert(!arr0);
  delete[] arr0;
  printf("Test passed: empty tree & default constructor!\n");

  //empty remove
  bt0.remove(333);
  assert(bt0.size()==0);
  assert(bt0.mRoot==NULL);
  assert(!bt0.contains(444));
  arr0 = bt0.toArray();
  assert(!arr0);
  delete[] arr0;
  printf("Test passed: empty remove!\n");

  //add to empty
  bt0.add(300);
  bt0.add(200);
  bt0.add(600);
  bt0.add(500);
  bt0.add(700);
  bt0.add(100);
  bt0.add(400);
  assert(bt0.size()==7);
  assert(bt0.contains(100));
  assert(bt0.contains(200));
  assert(bt0.contains(300));
  assert(bt0.contains(400));
  assert(bt0.contains(500));
  assert(bt0.contains(600));
  assert(bt0.contains(700));
  assert(!bt0.contains(0));
  arr0 = bt0.toArray();
  assert(arr0[0]==100);
  assert(arr0[1]==200);
  assert(arr0[2]==300);
  assert(arr0[3]==400);
  assert(arr0[4]==500);
  assert(arr0[5]==600);
  assert(arr0[6]==700);
  delete[] arr0;
  printf("Test passed: add empty!\n");

  //add same
  bt0.add(100);
  assert(bt0.size()==7);
  assert(bt0.contains(100));
  arr0 = bt0.toArray();
  assert(arr0[0]==100);
  delete[] arr0;
  printf("Test passed: add same!\n");
 
  //remove a non-exist element
  bt0.remove(0);
  assert(bt0.size()==7);
  assert(bt0.contains(100));
  arr0 = bt0.toArray();
  assert(arr0[0]==100);
  delete[] arr0;
  printf("Test passed: remove non-exist from tree!\n");
 
  //remove an element 
  bt0.remove(300);
  assert(bt0.mRoot);
  arr0 = bt0.toArray();
  assert(arr0[0]==100);
  assert(arr0[1]==200);
  assert(arr0[2]==400);
  assert(arr0[3]==500);
  assert(arr0[4]==600);
  assert(arr0[5]==700);
  delete[] arr0;

  bt0.remove(600);
  assert(bt0.size()==5);
  assert(!bt0.contains(300));
  assert(!bt0.contains(600));
  arr0 = bt0.toArray();
  assert(arr0[0]==100);
  assert(arr0[1]==200);
  assert(arr0[2]==400);
  assert(arr0[3]==500);
  assert(arr0[4]==700);
  delete[] arr0;
  printf("Test passed: remove from tree!\n");
  
  //add a removed element
  bt0.remove(200);
  bt0.add(200);
  assert(bt0.size()==5);
  assert(bt0.contains(200));
  arr0 = bt0.toArray();
  assert(arr0[0]==100);
  assert(arr0[1]==200);
  assert(arr0[2]==400);
  assert(arr0[3]==500);
  assert(arr0[4]==700);
  delete[] arr0;
  printf("Test passed: add back to tree!\n");

  //remove all
  bt0.remove(100);
  bt0.remove(200);
  bt0.remove(300);
  bt0.remove(400);
  bt0.remove(500);
  bt0.remove(700);
  assert(bt0.size()==0);
  assert(bt0.mRoot==NULL);
  arr0 = bt0.toArray();
  assert(!arr0);
  delete[] arr0;
  printf("Test passed: remove all!\n");


  //multiple trees
  //deep copy constructor
  BTree bt1;
  bt1.add(1);
  bt1.add(99);
  bt1.add(-99);
  bt1.add(88);
  bt1.add(-88);
  bt1.add(-1);
  BTree bt2(bt1);
  assert(bt2.mRoot != bt1.mRoot);

  bt1.remove(1);
  bt1.remove(1);
  bt2.add(9);
  bt2.add(9);
  bt2.remove(-88);
  bt2.remove(-88);
  bt2.add(100);
  bt2.add(100);
  assert(bt1.size()==5);
  assert(bt2.size()==7);

  assert(bt1.contains(-1));
  assert(bt1.contains(-88));
  assert(bt1.contains(-99));
  assert(bt1.contains(88));
  assert(bt1.contains(99));
  assert(!bt1.contains(1));
	
  assert(bt2.contains(9));
  assert(bt2.contains(1));
  assert(bt2.contains(99));
  assert(bt2.contains(88));
  assert(bt2.contains(-99));
  assert(bt2.contains(-1));
  assert(bt2.contains(100));
  assert(!bt2.contains(-88));

  int* arr1 = bt1.toArray();
  assert(arr1[0]==-99);
  assert(arr1[1]==-88);
  assert(arr1[2]==-1);
  assert(arr1[3]==88);
  assert(arr1[4]==99);
  delete[] arr1;

  int* arr2 = bt2.toArray();
  assert(arr2[0]==-99);
  assert(arr2[1]==-1);
  assert(arr2[2]==1);
  assert(arr2[3]==9);
  assert(arr2[4]==88);
  assert(arr2[5]==99);
  assert(arr2[6]==100);
  delete[] arr2;
  printf("Test passed: deep copy constructor!\n");



  //deep copy =
  BTree bt3;
  bt3.add(1);
  bt3.add(99);
  bt3.add(-99);
  bt3.add(88);
  bt3.add(-88);
  bt3.add(-1);
  BTree bt4;
  bt4.add(10);
  bt4.add(-10);
  bt4 = bt3;
  assert(bt4.mRoot != bt3.mRoot);
  assert(bt4.size() == bt3.size());
  int* arr3 = bt3.toArray();
  int* arr4 = bt4.toArray();
  for(int i = 0; i < bt3.size(); i++)
  {
    assert(arr3[i] == arr4[i]);
  }
  delete[] arr3;
  delete[] arr4;
  bt3.remove(1);
  bt3.remove(1);
  bt4.add(9);
  bt4.add(9);
  bt4.remove(-88);
  bt4.remove(-88);
  bt4.add(100);
  bt4.add(100);
  assert(bt3.size()==5);
  assert(bt4.size()==7);

  assert(bt3.contains(-1));
  assert(bt3.contains(-88));
  assert(bt3.contains(-99));
  assert(bt3.contains(88));
  assert(bt3.contains(99));
  assert(!bt3.contains(1));
	
  assert(bt4.contains(9));
  assert(bt4.contains(1));
  assert(bt4.contains(99));
  assert(bt4.contains(88));
  assert(bt4.contains(-99));
  assert(bt4.contains(-1));
  assert(bt4.contains(100));
  assert(!bt4.contains(-88));

  arr3 = bt3.toArray();
  assert(arr3[0]==-99);
  assert(arr3[1]==-88);
  assert(arr3[2]==-1);
  assert(arr3[3]==88);
  assert(arr3[4]==99);
  delete[] arr3;

  arr4 = bt4.toArray();
  assert(arr4[0]==-99);
  assert(arr4[1]==-1);
  assert(arr4[2]==1);
  assert(arr4[3]==9);
  assert(arr4[4]==88);
  assert(arr4[5]==99);
  assert(arr4[6]==100);
  delete[] arr4;
  printf("Test passed: deep copy =!\n");

  //multiple =
  BTree bt_em;
  bt_em = bt4 = bt3;
  assert(bt_em.size()==5 && bt3.size()==5 && bt4.size()==5); 
  assert(bt_em.mRoot!=bt3.mRoot && bt3.mRoot!=bt4.mRoot && bt_em.mRoot!=bt4.mRoot && bt4.mRoot && bt3.mRoot && bt_em.mRoot); 
  int* arr_em = bt_em.toArray();
  arr3 = bt3.toArray();
  arr4 = bt4.toArray();
  for(int i = 0; i < 5; i++)
  {
    assert(arr3[i] == arr4[i]);
    assert(arr_em[i] == arr4[i]);
  }
  delete[] arr_em;
  delete[] arr3;
  delete[] arr4;
  printf("Test passed: multiple =!\n");

  //self assignment
  bt4 = bt4;
  assert(bt4.size()==5);
  assert(bt4.mRoot); 
  arr4 = bt4.toArray();
  assert(arr4[0]==-99);
  assert(arr4[1]==-88);
  assert(arr4[2]==-1);
  assert(arr4[3]==88);
  assert(arr4[4]==99);
  delete[] arr4;
  printf("Test passed: self assignment!\n");


  //various remove
  //remove two children node 
  BTree bt5;
  bt5.add(0);
  bt5.add(2);
  bt5.add(-2);
  bt5.add(1);
  bt5.add(-1);
  bt5.add(3);
  bt5.add(-3);
  bt5.add(-4);
  bt5.add(5);
  bt5.add(4);
  bt5.remove(0);
  assert(bt5.size() == 9);
  assert(bt5.mRoot->value == 1 || bt5.mRoot->value == -1);
  int* arr5 = bt5.toArray();
  assert(arr5[0]==-4);
  assert(arr5[1]==-3);
  assert(arr5[2]==-2);
  assert(arr5[3]==-1);
  assert(arr5[4]==1);
  assert(arr5[5]==2);
  assert(arr5[6]==3);
  assert(arr5[7]==4);
  assert(arr5[8]==5);
  delete[] arr5;
  printf("Test passed: remove balenced root!\n");

  //remove one child node
  BTree bt6;
  bt6.add(0);
  bt6.add(2);
  bt6.add(-2);
  bt6.add(1);
  bt6.add(3);
  bt6.add(-3);
  bt6.remove(-2);
  assert(bt6.size() == 5);
  assert(bt6.mRoot->left->value == -3);
  int* arr6 = bt6.toArray();
  assert(arr6[0]==-3);
  assert(arr6[1]==0);
  assert(arr6[2]==1);
  assert(arr6[3]==2);
  assert(arr6[4]==3);
  delete[] arr6;
  printf("Test passed: remove one child node!\n");

  //remove leaf node
  bt6.remove(1);
  assert(bt6.size() == 4);
  assert(bt6.mRoot->right->left == NULL);
  arr6 = bt6.toArray();
  assert(arr6[0]==-3);
  assert(arr6[1]==0);
  assert(arr6[2]==2);
  assert(arr6[3]==3);
  delete[] arr6;

  bt6.remove(2);
  assert(bt6.size() == 3);
  assert(bt6.mRoot->right->value == 3);
  arr6 = bt6.toArray();
  assert(arr6[0]==-3);
  assert(arr6[1]==0);
  assert(arr6[2]==3);
  delete[] arr6;

  bt6.remove(0);
  assert(bt6.size() == 2);
  assert(bt6.mRoot->value == -3 || bt6.mRoot->value == 3);
  arr6 = bt6.toArray();
  assert(arr6[0]==-3);
  assert(arr6[1]==3);
  delete[] arr6;

  bt6.remove(3);
  assert(bt6.size() == 1);
  assert(bt6.mRoot->value == -3);
  arr6 = bt6.toArray();
  assert(arr6[0]==-3);
  delete[] arr6;

  bt6.remove(-3);
  assert(bt6.size() == 0);
  assert(bt6.mRoot == NULL);
  arr6 = bt6.toArray();
  assert(arr6==NULL);
  delete[] arr6;

  bt6.remove(12);
  assert(bt6.size() == 0);
  assert(bt6.mRoot == NULL);
  arr6 = bt6.toArray();
  assert(arr6==NULL);
  delete[] arr6;
  printf("Test passed: remove leaf node!\n");
  
  //only right
  bt6.add(1);
  bt6.add(2);
  bt6.add(3);
  bt6.add(4);
  bt6.add(5);
  bt6.remove(1);
  assert(bt6.size() == 4);
  assert(bt6.mRoot->value == 2);
  arr6 = bt6.toArray();
  assert(arr6[0]==2);
  assert(arr6[1]==3);
  assert(arr6[2]==4);
  assert(arr6[3]==5);
  delete[] arr6;

  bt6.remove(4);
  assert(bt6.size() == 3);
  assert(bt6.mRoot->value == 2);
  arr6 = bt6.toArray();
  assert(arr6[0]==2);
  assert(arr6[1]==3);
  assert(arr6[2]==5);
  delete[] arr6;
  bt6.remove(5);
  bt6.remove(3);
  bt6.remove(2);
  assert(bt6.size() == 0);
  assert(bt6.mRoot == NULL);
  arr6 = bt6.toArray();
  assert(arr6==NULL);
  delete[] arr6;
  printf("Test passed: remove only right node!\n");

  //only left
  bt6.add(5);
  bt6.add(4);
  bt6.add(3);
  bt6.add(2);
  bt6.add(1);
  bt6.remove(5);
  assert(bt6.size() == 4);
  assert(bt6.mRoot->value == 4);
  arr6 = bt6.toArray();
  assert(arr6[0]==1);
  assert(arr6[1]==2);
  assert(arr6[2]==3);
  assert(arr6[3]==4);
  delete[] arr6;

  bt6.remove(2);
  assert(bt6.size() == 3);
  assert(bt6.mRoot->value == 4);
  arr6 = bt6.toArray();
  assert(arr6[0]==1);
  assert(arr6[1]==3);
  assert(arr6[2]==4);
  delete[] arr6;
  bt6.remove(3);
  bt6.remove(1);
  bt6.remove(4);
  assert(bt6.size() == 0);
  assert(bt6.mRoot == NULL);
  arr6 = bt6.toArray();
  assert(arr6==NULL);
  delete[] arr6;
  printf("Test passed: remove only left node!\n");
  
  //to array
  BTree bt7;
  bt7.add(9);
  bt7.add(3);
  bt7.add(5);
  bt7.remove(3);
  bt7.remove(3);
  bt7.remove(3);
  bt7.add(3);
  bt7.add(3);
  bt7.add(3);
  bt7.add(3);
  bt7.add(4);
  bt7.add(0);
  bt7.add(8);
  bt7.add(2);
  bt7.add(17);
  assert(bt7.mRoot->value==9);
  assert(bt7.mRoot->right->value==17);
  assert(bt7.mRoot->left->value==5);
  assert(bt7.mRoot->left->right->value==8);
  assert(bt7.mRoot->left->left->value==3);
  assert(bt7.mRoot->left->left->right->value==4);
  assert(bt7.mRoot->left->left->left->value==0);
  assert(bt7.mRoot->left->left->left->right->value==2);
  assert(bt7.size()==8);
  assert(bt7.contains(9));
  assert(bt7.contains(17));
  assert(bt7.contains(0));
  assert(bt7.contains(2));
  assert(bt7.contains(3));
  assert(bt7.contains(4));
  assert(bt7.contains(8));
  assert(bt7.contains(5));
  int* arr7 = bt7.toArray();
  delete[] arr7;

  //extremly large tree
  BTree bt8;
  for(int i = 0; i < 1000; i++)
  {
    bt8.add(i);
  }
  for(int i = 0; i > -1000; i--)
  {
    bt8.add(i);
  }
  assert(bt8.size()==1999);
  int* arr8 = bt8.toArray();
  assert(arr8[1998]==999);
  assert(arr8[0]==-999);
  delete[] arr8;
  for(int i=-999; i<999; i++)
  {
    printf("%d\n", i+999);
    assert(bt8.contains(i));
  }
  printf("Test passed: extremly large tree!\n");

  printf("All test passed!\n");
  return 0;
}

