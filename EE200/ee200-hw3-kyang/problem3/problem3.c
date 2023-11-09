
#include "problem3.h"
#include "stdio.h"

double calculate(double x, char operation, double y)
{
  double rsl;
  switch(operation)
  {
    case '+' :
      rsl = x + y;
      break;
    case '-' :
      rsl = x - y;
      break;
    case '*' :
      rsl = x * y;
      break;
    case '/' :
      if ( y == 0)
      {
        printf("error: divisor cannot be zero!!!\n");
        return(0);
      }
      else
      {
        rsl = x / y;
      } 
      break;
    case '^' :
      if ( x == 0.0 && y <= 0.0 )
      {
        printf("error: zero can not have negative or zero prower!!!\n");
        return(0);
      }
      else if ( x < 0.0 && (int)y != y)
      {
        printf("error: negative number can not have decimal power!!!\n");
        return(0);
      }
      else
      {
        rsl = pow(x,y);
      }
      break;
    default:
      printf("error: no such operation!!!\n");
      return(0);
  }
  
  return(rsl);
}

