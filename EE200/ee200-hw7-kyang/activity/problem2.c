/* problem2.c - Activity summary */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// function to calculate the time limitation
int cal_limit(char * arg)
{
  char count_c[10];
  int i = 0;
  int count;
  char unit;
  time_t limitation;	
   
  // check if the char is a number 
  while(arg[i] < 58 && arg[i] > 47) 
  {
    count_c[i] = arg[i];
    i++;
  }
 
  // the next char is unit
  unit = arg[i];
  // if the next char is not \0, error, return -1
  if(arg[i+1] != '\0')
  {
    printf("usage:./summarize <count> <unit>, count is number , and unit is 'd' for day, 'w' for weak, 'y' for year\n");
    return(-1);
  }
  // complete count string
  count_c[i] = '\0';
  count = atoi(count_c); // convert string to number
  
  // set limitation according to unit
  switch(unit)
  {
    case 'd':
      limitation = count * 86400;
      break;

    case 'w':
      limitation = count * 86400 * 7;
      break;

    case 'y':
      limitation = count * 86400 * 365;
      break;

    default:
      printf("usage:./summarize <count> <unit>, count is number , and unit is 'd' for day, 'w' for weak, 'y' for year\n");
      return(-1);
  }
  return(limitation);
}

int main(int argc, char* argv[])
{
  time_t now = time(NULL);
  time_t log_time;

  char seconds[15]={0}; // temp array to save time stamp string in log(log time < 9999999999999999)
  char duration[4]={0}; // temp array to save exercise minutes string(exe minutes < 9999)
  int minutes; // save the sum of exercise minutes
  int tab_count; // count tabs in a line

  if(argc != 2)
  {
    printf("usage:./summarize <count> <unit>, count is number , and unit is 'd' for day, 'w' for weak, 'y' for year\n");
    return(-1);
  }
  time_t duration_limit = cal_limit(argv[1]); // the duration limitation we set
  
  if(duration_limit == -1)
  {
    return(0); // return 0 if wrong duration limitation
  }
  
  FILE* f_activity = fopen("activity.tsv", "r");
  if(f_activity != NULL) // check if having file stream
  {
    int i = 0;
    int j = 0;
    tab_count = 0;
    minutes = 0;
    int c;
    while(1)
    {
      c = fgetc(f_activity); // assign a char to c
      if(feof(f_activity))
      {
        break; //check if end of file
      }
      else if(c==EOF) // not end of file but return EOF
      {
	printf("error: Corrupt File\n");
	return(-1);
      }
      if(tab_count < 3) // characters before times
      {
        if(c != '\t' && c != '\n' && tab_count == 0) // collect log time string
	{
	  if(c != 45 && (c > 57 || c < 48))
	  {
	    printf("error: Invalid file content, wrong log time!\n");
	    return(-1);
	  }
	  seconds[i] = c;
          i++;  
	}
	else if( (c=='\t' || c=='\n') && tab_count == 0) // end log time collection
	{
	  seconds[i] = '\0'; // end log time string
          log_time = atoi(seconds); // change log time string to int
	  i = 0; // reset log time array
	  if(c=='\n')
	  {
	    tab_count = 0; // end of line, 3 columns, reset tab_count
	  }
    	}
	if( tab_count == 2 ) // exercise time characters
	{
	  if((now - log_time) <= duration_limit) // within in limitation
	  {
            if(c != '\t' && c != '\n') // collect exercise time string 
	    {
	      if(c > 57||c < 48)
	      {
	        printf("error: Invalid file content, wrong exercise time!\n");
	        return(-1);
	      }
	      duration[j] = c;
	      j++; 
    	    }
	    else if(c == '\t' || c == '\n') // end exercise time collection
	    {
	      duration[j] = '\0'; // end exe time string
	      minutes = minutes + atoi(duration); // sum up exe minutes
	      j = 0; // reset exe time array
	      if(c == '\n')
	      {
	        if(tab_count < 2)
		{
		  printf("error: Invalid file content, too few components!\n");
		  return(-1);
		}
		tab_count = 0; // end of line, 3 columns, reset tab_count
	      }
	    }
	  }
    	}
	if(c == '\t')
	{
          tab_count++; // count tab number
	  if(tab_count > 3)
	  {
	    printf("error: Invalid file content, too many components!\n");
	    return(-1);
	  }
	}       
      }
      else if(c == '\n' && tab_count == 3)
      {
	tab_count = 0; // end of line, all 4 columns, reset tab_count
      }
    }
    fclose(f_activity);
  }
  else
  {
    printf("error: missing file 'activity.tsv'\n");
    return(-1);
  }
  printf("Total exercise: %d minutes\n", minutes);
  return(0);
}
 
