/* problem3.c - Word counting */
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

int word_count(bool on_off, int *info)
{
  if(on_off)
  {
    (*info)++;
  }
}

int main(int argc, char* argv[])
{
  bool l, w, b, f, visible;
  l = 0;
  w = 0;
  b = 0;
  f = 0;

  int words = 0;
  int *words_p = &words;
  int lines = 0;
  int *lines_p = &lines;
  int bytes = 0;
  int *bytes_p = &bytes;
 
  visible = 0;

  int opt; 
  FILE *f_stream;

  while((opt = getopt(argc, argv, "lwc")) != -1)
  {
    switch(opt)
    {
      case 'l':
	l = 1;
        int lines = 0;	
	break;
      case 'w':
	w = 1;  
        int words = 0;	
	break;
      case 'c':
	b = 1;  
	break;
      case '?':
	printf("error: unknown option %c\n",optopt);
	break;
    }
  }

  if(optind+1 == argc && optind != 1)
  {
    f_stream = fopen(argv[optind], "r");
    f = 1;
  }
  else if(optind == argc && optind != 1)
  {
    f_stream = stdin;
    f = 0;
  }
  else if(optind == 1 && argc == 2)
  {
    l = 1;
    w = 1;
    b = 1;
    f_stream = fopen(argv[optind], "r");
    f = 1;
  }
  else if(optind ==1 && argc == 1)
  {
    l = 1;
    w = 1;
    b = 1;
    f_stream = stdin;
    f = 0;
  }
  else
  {
    printf("error: too many arguments\n");
    printf("usage: -l print the number of newline\n");
  }
 
  int c;

  do
  {
    c = fgetc(f_stream);
    if(c==EOF)
    {
      if(visible)
      {
        word_count(w, words_p);
      }
      break;
    }
    //printf("%c\n", c);
    if((c == '\t' || c == ' ' || c == '\n' || c == '\0') && visible == 1)
    {
      word_count(w, words_p);
      visible = 0;
    }
    if(c == '\n' || c == '\0')
    {
      word_count(l, lines_p);
      visible = 0;
    }
    if(c)
    {
      word_count(b, bytes_p);
      if(c != '\t' && c != ' ' && c != '\n' && c != '\0')
      {
        visible = 1;
      }
    }
  }
  while(1);

  if(l)
  {
    printf("%d ", lines);
  }
  if(w)
  {
    printf("%d ", words);
  }
  if(b)
  {
    printf("%d ", bytes);
  }
  if(f)
  {
    printf("%s\n", argv[argc-1]);
    fclose(f_stream);
  }
  else
  {
    printf("\n");
  }
  
  return(0);
}

