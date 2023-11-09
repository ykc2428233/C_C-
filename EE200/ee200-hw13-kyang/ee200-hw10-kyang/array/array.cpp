/*#include "array.h"
#include "cstdlib"
#include "iostream"
using namespace std;
// Not much to say here.  Good luck!

template <typename T>
int Array<T>::size()
{
  return(mSize);
}

template <typename T>
void Array<T>::append(int x)
{
  //mArray = (int*)realloc(mArray, (mSize+1)*sizeof(int));
  T* temp = new T[mSize + 1];
  for(int i = 0; i < mSize; i++)
  {
    temp[i] = mArray[i];
  }
  //this->push_back(x)
  temp[mSize] = x;
  delete[] mArray;
  mSize = mSize + 1;
  mArray = temp;
}

template <typename T>
void Array<T>::append(const Array<T>& y)
{
  //this->mArray = (int*)realloc(this->mArray, (this->mSize + y.mSize)*sizeof(int));
  T* temp = new int[mSize + y.mSize];
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

template <typename T>
Array<T>& Array<T>::operator+(const Array<T>& other)
{
  T* temp = new T[this->mSize + other.mSize];
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

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
  T* temp = new T[other.mSize];
  for(int i = 0; i < other.mSize; i++)
  {
    temp[i] = other.mArray[i];
  }
  delete[] this->mArray;
  this->mSize = other.mSize;
  this->mArray = temp;
  return(*this);
}

template <typename T>
T& Array<T>::operator[](int i)
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

template <typename T>
Array<T>::Array() : mSize(1),
		    mArray(new T[1]) 
{
  mArray[0] = 0;
}

template <typename T>
Array<T>::Array(int length, T value) : mSize(length), 
				       mArray(new T[length])
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

template <typename T>
Array<T>::Array(int length, T* value) : mSize(length), 
	  			        mArray(new T[length])
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

template <typename T>
Array<T>::Array(const Array<T>& arr) : mSize(arr.mSize),
				       mArray(new T[arr.mSize])
{
  for(int i = 0; i < mSize; i++)
  {
    mArray[i] = arr.mArray[i];
  }
}

template <typename T>
Array<T>::~Array()
{
  delete [] this->mArray;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const Array<T>& arr)
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
*/
