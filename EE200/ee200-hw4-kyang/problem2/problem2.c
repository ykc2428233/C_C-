
#include "problem2.h"

void print_time(time_t time)
{
  int year, day, hour, minute, second;
 
  const char * month[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
  const char * wday[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

  year = gmtime(&time)->tm_year + 1900;
  day = gmtime(&time)->tm_mday;
  hour = gmtime(&time)->tm_hour;
  minute = gmtime(&time)->tm_min;
  second = gmtime(&time)->tm_sec;
  
  const char * w = wday[gmtime(&time)->tm_wday]; 
  
  const char * m = month[gmtime(&time)->tm_mon]; 

  printf("%s, %s %02d, %d %02d:%02d:%02d\n", w, m, day, year, hour, minute, second);

}

