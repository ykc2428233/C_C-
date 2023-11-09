
#include "problem3.h"


int main(int argc, char* argv[])
{

  char * str =  "Put anything here that you think is appropriate to test your function";
  unsigned int h[26];
  find_frequency(str, 69, h);
  
  unsigned int h2[26];
  find_frequency(NULL, 80, h2);
  
  char * str_n = "iweufdkn 9ewirdj wureriotjg99 )() 8tweifjd"; 
  find_frequency(str_n, 80, h);
  
  //for( int i = 0; i<26; i++)
  //{
  //  printf("%c : %u\n", i+65, h[i]);
  //}
  return(0);
}

