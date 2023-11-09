
#include "problem1.h"
#include "stdio.h"
#include "assert.h"

int main(int argc, char* argv[])
{

  char board[3][3]={{'x','x',' '},
	            {' ',' ',' '},
	            {' ',' ',' '}};
  assert(check_win(board) == '\0');

  char board1[3][3]={{'x',' ',' '},
	             {'o','x',' '},
	             {' ','o','x'}};
  assert(check_win(board1) == 'x');

  char board2[3][3]={{'o',' ',' '},
	             {'o','x',' '},
	             {'o','x','x'}};
  assert(check_win(board2) == 'o');

  char board3[3][3]={{'o','x','o'},
	             {'o','x','x'},
	             {'x','o','x'}};
  assert(check_win(board3) == '.');

  char board4[3][3]={{'o','x','o'},
	             {'?','x','x'},
	             {'x','o','x'}};
  assert(check_win(board4) == '\0');

  char board5[3][3]={{'x',' ',' '},
	             {' ',' ',' '},
	             {' ',' ',' '}};
  assert(check_win(board5) == ' ');

  char board6[3][3]={{'x',' ','o'},
	             {'x',' ','o'},
	             {'x',' ','o'}};
  assert(check_win(board6) == '\0');

  char board7[3][3]={{'o',' ','x'},
	             {'x','o',' '},
	             {' ',' ','o'}};
  assert(check_win(board7) == 'o');

  assert(check_win(NULL) == '\0');

  return(0);
}

