#include <iostream>
using namespace std;

class BoundedValue 
{
  private:
	  int mMin;
	  int mMax;
	  int mValue;
  public:
	  int set_min(int min);
	  int set_max(int max);
	  int set_value(int value);
	  int get_value();
          BoundedValue operator+(const BoundedValue& other);
          BoundedValue operator+(int value);
          BoundedValue operator=(int value);
	  BoundedValue(int min, int max, int value);
	  BoundedValue();
	  BoundedValue(const BoundedValue& orig);
};

std::ostream & operator<<(std::ostream & stream, const BoundedValue& b)
{
  stream << b.value;
  return stream;
}
	  
BoundedValue::BoundedValue(int min, int max, int value)
{
  std::cout << "BoundedValue::BoundedValue(int int int)" << std::endl;
  mMin = min;
  mMax = max;
  mValue = value;
}

BoundedValue::BoundedValue()
{
  std::cout << "BoundedValue::BoundedValue" << std::endl;
  mMin = 0;
  mMax = 0;
  mValue = 0;
}

BoundedValue::BoundedValue(const BoundedValue& orig)
{
  std::cout << "BoundedValue::BoundedValue(orig)" << std::endl;
  mMin = orig.mMin;
  mMax = orig.mMax;
  mValue = orig.mValue;
}

int BoundedValue::set_min(int min)
{
  mMin = min;
  return(0);
}

int BoundedValue::set_max(int max)
{
  mMax = max;
  return(0);
}

int BoundedValue::set_value(int value)
{
  if(value < mMin)
  {
    mValue = mMin;
  }
  else if(value > mMax)
  {
    mValue = mMax;
  }
  else
  {
    mValue = value;
  }
  return(0);
}

int BoundedValue::get_value()
{
  return(mValue);
}
          
BoundedValue BoundedValue::operator+(const BoundedValue& other)
{
  //std::cout << this->mValue << std::endl;
  //std::cout << other.mValue << std::endl;
  ////a->b is shorthand for (*a).b;	

  BoundedValue r(mMin, mMax, mValue + other.mValue);
  r.mMax = this->mMax;
  r.mMin = mMin;
  //r.mValue = this->mValue + other.mValue;
  r.set_value(this->mValue + other.mValue);
  return(r);
}

BoundedValue BoundedValue::operator=(int value)
{
  set_value(value);
  return(*this);
}

int main()
{
  std::cout << "Hello World!" << std::endl;
  
  BoundedValue bv;
  bv.set_max(40);
  bv.set_min(0);
  bv.set_value(100);
  
  BoundedValue bv1;
  bv1.set_max(5);
  bv1.set_min(0);
  bv1.set_value(100);
  
  BoundedValue bv2 = bv1; //copy constructor, construct an object with an exsiting object, a constructor is called.
  /*bv2.set_max(60);
  bv2.set_min(0);
  bv2.set_value(100);*/
  
  //bv2 = bv + bv1;
  //bv2 = bv1 + bv;
  //bv2=bv.operator+(bv1);
  
  std::cout << "bv[0,50]:" << bv.get_value() << std::endl;
  std::cout << "bv1[0,5]:" << bv1.get_value() << std::endl;
  std::cout << "bv2[0,60]:" << bv2.get_value() << std::endl;
  return(0);
}
