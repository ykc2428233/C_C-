#include "array.h"
#include "cstdlib"
#include "iostream"
using namespace std;
// Not much to say here.  Good luck!

int Array::size()
{
  return(mSize);
}

void Array::append(int x)
{
  //mArray = (int*)realloc(mArray, (mSize+1)*sizeof(int));
  int* temp = new int[mSize + 1];
  for(int i = 0; i < mSize; i++)
  {
    temp[i] = mArray[i];
  }
  temp[mSize] = x;
  delete[] mArray;
  mSize = mSize + 1;
  mArray = temp;
}

void Array::append(const Array& y)
{
  //this->mArray = (int*)realloc(this->mArray, (this->mSize + y.mSize)*sizeof(int));
  int* temp = new int[mSize + y.mSize];
  for(int i = 0; i < mSize; i++)
  {
    temp[i] = mArray[i];
  }
  for(int i = 0; i < y.mSize; i++)
  {
    temp[i + mSize] = y.mArray[i];
  }
  delete[] mArray;
  this->mSize = this->mSize + y.mSize;
  mArray = temp;
}

Array& Array::operator+(const Array& other)
{
  int* temp = new int[this->mSize + other.mSize];
  for(int i = 0; i < this->mSize; i++)
  {
    temp[i] = this->mArray[i];
  }
  
  for(int i = 0; i < other.mSize; i++)
  {
    temp[i + this->mSize] = other.mArray[i];
  }
  delete[] this->mArray;
  this->mSize = this->mSize + other.mSize;
  this->mArray = temp;
  return(*this);
}

Array& Array::operator=(const Array& other)
{
  int* temp = new int[other.mSize];
  for(int i = 0; i < other.mSize; i++)
  {
    temp[i] = other.mArray[i];
  }
  delete[] this->mArray;
  this->mSize = other.mSize;
  this->mArray = temp;
  return(*this);
}

int& Array::operator[](int i)
{
  if(i < 0 || i > this->mSize)
  {
    std::cout << "error: invalid index" << std::endl;
    exit(0);
  }
  else
  {
    return(this->mArray[i]);
  }
}

Array::Array() : mSize(0),
		 mArray(NULL) 
{
  //mArray[0] = 0;
}

Array::Array(int length, int value) : mSize(length), 
				      mArray(new int[length])
{
  if(length > 0)
  {
    for(int i = 0; i < length; i++)
    {
      mArray[i] = value;
    }
  }
  else
  {
    printf("error: invalid length of Array!\n");
  }
}

Array::Array(int length, int* value) : mSize(length), 
				       mArray(new int[length])
{
  if(length > 0)
  {
    for(int i = 0; i < length; i++)
    {
      mArray[i] = value[i];
    }
  }
  else
  {
    printf("error: invalid length of Array!\n");
  }
}

Array::Array(const Array& arr) : mSize(arr.mSize),
				 mArray(new int[arr.mSize])
{
  for(int i = 0; i < mSize; i++)
  {
    mArray[i] = arr.mArray[i];
  }
}

Array::~Array()
{
  delete [] this->mArray;
}

std::ostream& operator<<(std::ostream& stream, const Array& arr)
{
  stream << "[";
  for(int i = 0; i < arr.mSize; i++)
  { 
    if(i == arr.mSize - 1)
    { 
      stream << arr.mArray[i];
    }
    else
    { 
      stream << arr.mArray[i] << ", ";
    }    
  }
  stream << "]";
  return(stream);
}

