/* problem1.c - implementation of Linux `tree` */
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void print_prefix(int level)
{
  for(int i=0; i<level; i++)
  {
    printf("    ");
  }

}

int dir_name_superman(char *current_dir, char *name, int level)
{
  DIR *curr_dir;
  struct dirent * dir_info;
  char *temp_name;

  char buffer[2560];

  unsigned char temp_type;
  char *absolute_path;


  // print the current file name
  if(current_dir == NULL)
  {
    printf("error:Missing dir!!!");
  }
  
  // get a file stream of current dir's file  
  curr_dir = opendir(current_dir);
  if(!curr_dir)
  {
    printf("error:can not open directory %s\n", current_dir);
    return(-1);
  }
  else
  {
    print_prefix(level);
    if(name!=NULL)
    {
      printf("%s\n", name);
    }
    else
    {
      printf("%s\n", current_dir);
    }
  }

  
  while((dir_info = readdir(curr_dir)) != NULL)
  {
    temp_name = dir_info->d_name;
    temp_type = dir_info->d_type;

    if(temp_name[0] == '.')
    {
      continue;
    }
    // if not a directory
    if(temp_type != DT_DIR)
    {
      print_prefix(level+1);
      printf("%s\n",temp_name);
    }
    else // if is a directory
    {
      snprintf(buffer, 2560, "%s/%s", current_dir, temp_name);
      dir_name_superman(buffer, temp_name, level+1); // recursion on this dir
    }
  }
  closedir(curr_dir);
  return(0); 
}

int main(int argc, char* argv[])
{
  if(argc==1)
  {
    dir_name_superman(".", NULL, 0);
  }
  else if(argc==2)
  {
    dir_name_superman(argv[1], NULL, 0);
  }

  return(0);
}

