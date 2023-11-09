#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstddef>
#include <iostream>

class OutOfBoundsException : public std::exception
{
  private:
    const char* mMsg;
  public:
    OutOfBoundsException(const char* msg)
    {
      mMsg = msg;
    }
    virtual const char* what() const throw() 
    {
      return mMsg;
    }
};

template<typename T>
class LinkedList
{
  // You'll need to fill in the function declarations here, since writing them
  // correctly is half the challenge of some of these functions.  Be careful to
  // give them the same names as specified in the README, and pay special
  // attention to things which should be const, references, or both.

  // Note that if your function declarations are incorrect, the autograder will
  // fail to compile.  We'll make sure the autograder is at least able to test
  private:
	class Node 
	{
	  public: 
	  	T mData;
	  	Node* mNext;

		Node(const T& data) : mData(data),
	  	      	              mNext(NULL)
	  	{}

	  	Node(const T& data, Node* node) : mData(data),
	  	      		                  mNext(node)
	  	{}

	  	int get_data()
          	{
          	  return(mData);
	  	}

	};

	int mSize;
	Node* mHead;

  public:

	int size() const
	{
	  return mSize;
	}

	Node* getNode(int n) const
	{
	  if( (n >= mSize && n!= 0) || n < 0)
	  {
            throw OutOfBoundsException("error: index out of bounds!!!");
	  }
	  else
	  {
	    Node* current = mHead;
	    for(int i=0; i<n; i++)
	    {
	      current = current->mNext;
	    } 
	    return(current);
          }
	}

	T getItem (int n) const
	{
	  return(this->getNode(n)->mData);
	}

	void insert(T x, int pos)
	{
          mSize += 1;
	  Node* node = new Node(x, this->getNode(pos)); 
	  if(pos == 0)
	  {
	    mHead = node;  
	  }
	  else
	  {
	    this->getNode(pos-1)->mNext = node;
	  }
	}

	void remove(int pos)
        {
	  Node* temp = this->getNode(pos);
	  if(pos == 0)
	  {
	    this->mHead = this->getNode(1);
	  }
	  else if(pos == this->size()-1)
	  {
	    this->getNode(pos-1)->mNext = NULL;
	  }
	  else
	  {
	    this->getNode(pos-1)->mNext = this->getNode(pos+1);
	  }
	  delete temp;
	  mSize -= 1;
	}

	LinkedList& operator=(const LinkedList& ll)
	{
	  if(this == &ll)
	  {
	    return(*this);
	  }
	  else
	  {
	    Node* current = new Node(ll.getItem(ll.size()-1));//
	    for(int i=ll.mSize-2; i>=0; i--)
	    {
	      Node* previous  = new Node(ll.getItem(i), current);
	      current = previous;
	    }
	    Node* tempHead = current;
	    int tempSize = this->size();
	    for(int i=0; i<tempSize; i++)
	    {
	      this->remove(this->mSize-1);
	    }
	    this->mSize = ll.mSize;
	    this->mHead = tempHead;
	    return(*this);
	  }
	}

  //Constructor
	LinkedList() : mSize(0),
	               mHead(NULL)
	{}

        LinkedList(int length, Node* node) : mSize(length),
                                             mHead(node)
        {}

	LinkedList(int length, T* values) : mSize(length)
	{
	  Node* current = new Node(values[length-1]);
	  for(int i=length-2; i>=0; i--)
	  {
	    Node* previous = new Node(values[i], current);
	    current = previous;
 	  }
 	  mHead = current;
	}

	LinkedList(const LinkedList& ll) : mSize(ll.mSize)
	{
	  Node* current = new Node(ll.getItem(ll.mSize-1));
	  for(int i=ll.mSize-2; i>=0; i--)
	  {
	    Node* previous  = new Node(ll.getItem(i), current);
	    current = previous;
	  }
	    mHead = current;
	}

  //Destructor
	~LinkedList()
	{
	  while(mHead != NULL)
	  {
	    Node* temp = mHead->mNext;
	    delete mHead;
	    mHead = temp;
	  }
	}
};


#endif
