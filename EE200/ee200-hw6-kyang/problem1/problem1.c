#include "problem1.h"
#include "stdlib.h"
#include "stdbool.h"
#include "stdio.h"

char check_win(char board[3][3])
{
  int x_num = 0;
  int o_num = 0;
  bool x_win = 0;  
  bool o_win = 0;  
  
  if(board != NULL)
  {
    for(int i = 0; i < 3; i++)
    {
      for(int j = 0; j < 3; j++)
      {
        if(board[i][j] == 'o')
        {
          o_num++;
        }
        else if(board[i][j] == 'x')
        {
          x_num++;
        }
        else if(board[i][j] != ' ')
        {
          return('\0');
        }
      }
    }

    if(abs(x_num - o_num) > 1)
    {
      return('\0');
    }

    for( int i = 0; i < 3; i++)
    {
      if((board[i][0]==board[i][1] && board[i][0]==board[i][2] && board[i][0]=='o') ||
         (board[0][i]==board[1][i] && board[0][i]==board[2][i] && board[0][i]=='o') ||	    
         (board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]=='o') ||	    
         (board[2][0]==board[1][1] && board[2][0]==board[0][2] && board[2][0]=='o'))
      {
        o_win = 1;
      } 
      if((board[i][0]==board[i][1] && board[i][0]==board[i][2] && board[i][0]=='x') ||
         (board[0][i]==board[1][i] && board[0][i]==board[2][i] && board[0][i]=='x') ||	    
         (board[0][0]==board[1][1] && board[0][0]==board[2][2] && board[0][0]=='x') ||	    
         (board[2][0]==board[1][1] && board[2][0]==board[0][2] && board[2][0]=='x'))
      {
        x_win = 1;
      } 
    }
    if(x_win && o_win) 
    {
      return('\0');
    }
    if(x_win) 
    {
      return('x');
    }
    if(o_win) 
    {
      return('o');
    }
    if(!(o_win || x_win) && (x_num + o_num == 9)) 
    {
      return('.');
    }
    else if(!(o_win || x_win))
    {
      return(' '); 
    }
  }

  return('\0');
}

