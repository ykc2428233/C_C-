#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
template<typename T>
class Array{
  // You'll need to fill in the function declarations here, since writing them
  // correctly is half the challenge of some of these functions.  Be careful to
  // give them the same names as specified in the README, and pay special
  // attention to things which should be const, references, or both.

  // Note that if your function declarations are incorrect, the autograder will
  // fail to compile.  We'll make sure the autograder is at least able to test
  // compiling your code before the submission deadline.
 
  private:
	int mSize;
	T* mArray;
  public:
	
	int size()
	{
	  return(mSize);
	}
	
	void append(T x)
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

	void append(const Array<T>& y)
	{
	  //this->mArray = (int*)realloc(this->mArray, (this->mSize + y.mSize)*sizeof(int));
	  T* temp = new T[mSize + y.mSize];
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
// Constructors
        Array() : mSize(0),
		  mArray(NULL) 
	{}

	Array(int length, T value) : mSize(length), 
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

	Array(int length, T* values) : mSize(length), 
	  			       mArray(new T[length])
	{
	  if(length > 0)
	  {
	    for(int i = 0; i < length; i++)
	    {
	      mArray[i] = values[i];
	    }
	  }
	  else
	  {
	    printf("error: invalid length of Array!\n");
	  }
	}
	Array(const Array& arr) : mSize(arr.mSize),
				  mArray(new T[arr.mSize])
	{
	  for(int i = 0; i < mSize; i++)
	  {
	    mArray[i] = arr.mArray[i];
	  }
	}
//Destructor
	~Array()
	{
	  delete [] this->mArray;
	}
//Operands
	Array& operator=(const Array& arr)
	{
	  T* temp = new T[arr.mSize];
	  for(int i = 0; i < arr.mSize; i++)
	  {
	    temp[i] = arr.mArray[i];
	  }
	  delete[] this->mArray;
	  this->mSize = arr.mSize;
	  this->mArray = temp;
	  return(*this);
	}

	T& operator[](int i)
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

        Array& operator+(const Array& arr)
	{
	  T* temp = new T[this->mSize + arr.mSize];
	  for(int i = 0; i < this->mSize; i++)
	  {
	    temp[i] = this->mArray[i];
	  }
	  
	  for(int i = 0; i < arr.mSize; i++)
	  {
	    temp[i + this->mSize] = arr.mArray[i];
	  }
	  delete[] this->mArray;
	  this->mSize = this->mSize + arr.mSize;
	  this->mArray = temp;
	  return(*this);
	}

	friend std::ostream& operator<<(std::ostream& stream, const Array<T>& arr)
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
};


#endif
