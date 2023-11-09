
#include "problem2.h"
#include "stdio.h"
#include "math.h"
#include "assert.h"

int main(int argc, char* argv[])
{
  assert(find_power(1) == 1);
  assert(find_power(-1) == 0);
  assert(find_power(0) == 0);
  assert(find_power(20) == 16);
  assert(find_power(5) == 4);
  assert(find_power(12) == 8);
  return(0);
}

