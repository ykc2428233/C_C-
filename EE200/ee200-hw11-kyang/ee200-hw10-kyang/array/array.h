#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
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
	int* mArray;
  public:
	int size();
	//void initialize(int size, int val);
	//void cleanup();
	void append(int x);
	void append(const Array& y);
// Constructors
        Array();
	Array(int length, int value);
	Array(int length, int* values);
	Array(const Array& arr);
//Destructor
	~Array();
//Operands
	Array& operator=(const Array& arr);
	int& operator[](int i);
        Array& operator+(const Array& arr);
	friend std::ostream& operator<<(std::ostream& stream, const Array& arr);
};


#endif
