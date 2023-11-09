#include "array.h"
#include "cstdlib"
#include "iostream"
using namespace std;
// Not much to say here.  Good luck!

int Array::size()
{
  return(mSize);
}

void Array::initialize(int size, int val)
{
  if(size > 0)
  {
    mSize = size;
    mArray = (int*)malloc(size*sizeof(int));
    for(int i = 0; i < mSize; i++)
    {
      mArray[i] = val;
    }
  }
  else
  {
    mSize = 0;
    mArray = NULL;
  }
}

void Array::cleanup()
{
  free(mArray); 
}

void Array::append(int x)
{
  this->mSize = this->mSize + 1;
  mArray = (int*)realloc(mArray, (mSize)*sizeof(int));
  mArray[mSize - 1] = x;
}

void Array::append(const Array& y)
{
  this->mArray = (int*)realloc(this->mArray, (this->mSize + y.mSize)*sizeof(int));
  for(int i = 0; i < y.mSize; i++)
  {
    this->mArray[this->mSize+i] = y.mArray[i];
  }
  this->mSize = this->mSize + y.mSize;
}

Array& Array::operator=(const Array& other)
{
  this->mSize = other.mSize;
  this->mArray = (int*)realloc(this->mArray, this->mSize*sizeof(int));
  for(int i = 0; i < this->mSize; i++)
  {
    this->mArray[i] = other.mArray[i];
  }
  return(*this);
}

int& Array::operator[](int i)
{
  if(i < 0 || i >= this->mSize)
  {
    std::cout << "error: invalid index" << std::endl;
    exit(0);
  }
  else
  {
    return(this->mArray[i]);
  }
}
