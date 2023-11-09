
#include "problem2.h"
#include "stddef.h"

int main(int argc, char* argv[])
{

  char s[] = "MAKE THIS LOWERCASE";
  lower(s);

  lower(NULL);

  char s_1[] = "NIHAO? zaiganma? v50! Sudu!!!";
  lower(s_1);

  return(0);
}

