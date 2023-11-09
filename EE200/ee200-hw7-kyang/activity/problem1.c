/* problem1.c - Activity log */
#include <stdio.h>
#include <time.h>

//check the first argv is number
int number_s(char * arg2) 
{
  int i = 0;
  while(arg2[i] != '\0')
  {
    if(arg2[i] > 57 || arg2[i] < 48)
    {
      return(1);
    }
    i++;
  }
  return(0);  
}

//check space in sting
int space_s(char * args)
{
  int i = 0;
  while(args[i] != '\0')
  {
    if(args[i] == 32)
    {
      return(1);
    }
    i++;
  }
  return(0);  
}

int main(int argc, char* argv[])
{
  time_t seconds;
  seconds = time(NULL);

  if(argc == 4 && !space_s(argv[1]) && !number_s(argv[2]))
  { 
    FILE *f_log = fopen("activity.tsv", "a");
    fprintf(f_log, "%ld\t%s\t%s\t%s\n",seconds, argv[1], argv[2], argv[3]);
    fclose(f_log);
  }
  else if(argc == 3 && !space_s(argv[1]) && !number_s(argv[2]))
  {
    FILE *f_log = fopen("activity.tsv", "a");
    fprintf(f_log, "%ld\t%s\t%s\n",seconds, argv[1], argv[2]);
    fclose(f_log);
  }
  else
  {
    printf("usage: ./log <activity> <duration(in minutes) <\"Notes\">\n");
  }

  return(0);
}

