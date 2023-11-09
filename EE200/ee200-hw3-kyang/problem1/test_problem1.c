
#include "problem1.h"
#include "assert.h"

int main(int argc, char* argv[])
{
  assert(print_factors(23000) == 0);
  print_factors(7);
  assert(print_factors(20) == 0);
  assert(print_factors(1) == -1);
  assert(print_factors(-10) == -1);
  assert(print_factors(0) == -1);

  return(0);
}

